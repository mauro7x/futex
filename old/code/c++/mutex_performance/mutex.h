#ifndef __MUTEX_H__
#define __MUTEX_H__

#include "generic_mutex.h"
#include "mutex_v0.h"
#include "mutex_v1.h"
#include "mutex_v2.h"
#include "mutex_v3.h"

class Mutex : public GenericMutex {
   private:
    GenericMutex* m;

   public:
    Mutex(const int version);
    void lock();
    void unlock();
    ~Mutex();
};

#endif  // __MUTEX_H__