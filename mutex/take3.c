#include <stdatomic.h>

typedef struct mutex {
    // 0 == unlocked
    // 1 == locked, no waiters
    // 2 == locked, one or more waiters
    volatile int flag;
} mutex_t;

void init(struct mutex *m) {
    m->flag = 0;
}

void lock(struct mutex *m) {
    int c;
    if ((c = cmpxchg(&m->flag, 0, 1)) != 0) {
        if (c != 2)
            c = xchg(&m->flag, 2);
        while (c != 0) {
            futex_wait(&m->flag, 2);
            c = xchg(&m->flag, 2);
        }
    }
}

void unlock(struct mutex *m) {
    if (atomic_dec(&m->flag) != 1) {
        m->flag = 0;
        futex_wake(&m->flag, 1);
    }
}