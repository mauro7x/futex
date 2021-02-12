#include "lock.h"
#include "x86.h"

void init(struct lock *lk) {
    clear(&lk->flag);
}

void acquire(struct lock *lk) {
    while(xchg(&lk->flag, 1));
}

void release(struct lock *lk) {
    clear(&lk->flag);
}