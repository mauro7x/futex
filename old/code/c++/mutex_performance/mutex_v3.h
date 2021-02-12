#ifndef __MUTEX_V3_H__
#define __MUTEX_V3_H__

#include <atomic>

#include "aux.h"
#include "futex.h"
#include "generic_mutex.h"

class Mutex_v3 : public GenericMutex {
   private:
    /**
     * 0 == unlocked,
     * 1 == locked, no waiters,
     * 2 == locked, with waiters.
     */
    std::atomic<int> status;

   public:
    Mutex_v3();
    void lock();
    void unlock();
    ~Mutex_v3();
};

#endif  // __MUTEX_V3_H__