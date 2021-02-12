#ifndef __MUTEX__
#define __MUTEX__

#include <stdatomic.h>

typedef struct mutex {
    atomic_flag flag;
} mutex_t;

void init(struct mutex *m);
void lock(struct mutex *m);
void unlock(struct mutex *m);

#endif // __MUTEX__