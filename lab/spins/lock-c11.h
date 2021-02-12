#ifndef __LOCK_C11__
#define __LOCK_C11__

#include <stdatomic.h>

typedef struct lock {
    atomic_flag flag;
} lock_t;

void init(struct lock *lk);
void acquire(struct lock *lk);
void release(struct lock *lk);

#endif // __LOCK_C11__