#ifndef __MUTEX_V0_H__
#define __MUTEX_V0_H__

#include <mutex>

#include "generic_mutex.h"

class Mutex_v0 : public GenericMutex {
   private:
    std::mutex m;

   public:
    Mutex_v0();
    void lock();
    void unlock();
    ~Mutex_v0();
};

#endif  // __MUTEX_V0_H__