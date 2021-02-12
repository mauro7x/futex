#include <stdatomic.h>
#include "mutex.h"

void init(struct mutex *m) {
    atomic_flag_clear(&m->flag);
}

void lock(struct mutex *m) {
    while(atomic_flag_test_and_set(&m->flag))
        sys_yield();
}

void unlock(struct mutex *m) {
    atomic_flag_clear(&m->flag);
}
