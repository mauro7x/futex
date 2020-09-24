#ifndef __MUTEX_V2_H__
#define __MUTEX_V2_H__

#include <atomic>

#include "aux.h"
#include "futex.h"
#include "generic_mutex.h"

class Mutex_v2 : public GenericMutex {
   private:
    std::atomic<bool> taken;

   public:
    Mutex_v2();
    void lock();
    void unlock();
    ~Mutex_v2();
};

#endif  // __MUTEX_V2_H__