#ifndef __LOCK__
#define __LOCK__

// lock.h
typedef struct lock {
    volatile int flag;
} lock_t;

void init(struct lock *lk);
void acquire(struct lock *lk);
void release(struct lock *lk);

#endif // __LOCK__