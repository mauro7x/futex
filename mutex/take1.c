#include <stdatomic.h>

typedef struct mutex {
    // 0 == unlocked
    // >0 == locked
    volatile int flag;
} mutex_t;

void init(struct mutex *m) {
    m->flag = 0;
}

void lock(struct mutex *m) {
    int c;
    while ((c = atomic_inc(&m->flag)) != 0) futex_wait(&m->flag, c + 1);
}

void unlock(struct mutex *m) {
    m->flag = 0;
    futex_wake(&m->flag, 1);
}