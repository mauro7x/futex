// 10. Other Synchronization Primitives

#include "paper_interfaces.h"

class Mutex3 {
   private:
    int val;

   public:
    Mutex3() : val(0) {}

    void lock() {
        int c;
        if ((c = cmpxchg(val, 0, 1)) != 0) {
            if (c != 2)
                c = xchg(val, 2);
            while (c != 0) {
                futex_wait(&val, 2);
                c = xchg(val, 2);
            }
        }
    }

    void unlock() {
        if (atomic_dec(val) != 1) {
            val = 0;
            futex_wake(&val, 1);
        }
    }
};

class Barrier {
   public:
    Barrier(unsigned int needed)
        : lock(), event(0), still_needed(needed), initial_needed(needed) {}

    void wait() {
        lock.lock();
        if (still_needed-- > 1) {
            unsigned int ev = event;
            lock.unlock();
            do
                futex_wait(&event, ev);
            while (event == ev);
        } else {
            ++event;
            still_needed = initial_needed;
            futex_wake(&event, INT_MAX);
            lock.unlock();
        }
    }

   private:
    Mutex3 lock;
    unsigned int event;
    unsigned int still_needed;
    unsigned int initial_needed;
};