#include <stdatomic.h>
#include "lock-c11.h"

void init(struct lock *lk) {
    atomic_flag_clear(&lk->flag);
}

void acquire(struct lock *lk) {
    while(atomic_flag_test_and_set(&lk->flag));
}

void release(struct lock *lk) {
    atomic_flag_clear(&lk->flag);
}