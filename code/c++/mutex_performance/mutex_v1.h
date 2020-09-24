#ifndef __MUTEX_V1_H__
#define __MUTEX_V1_H__

#include <atomic>

#include "aux.h"
#include "generic_mutex.h"

class Mutex_v1 : public GenericMutex {
   private:
    std::atomic<bool> taken;

   public:
    Mutex_v1();
    void lock();
    void unlock();
    ~Mutex_v1();
};

#endif  // __MUTEX_V1_H__