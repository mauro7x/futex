// 4. Mutex, Take 1

#include "paper_interfaces.h"

class Mutex {
   private:
    int val;

   public:
    Mutex() : val(0) {}

    void lock() {
        int c;
        while ((c = atomic_inc(val)) != 0) futex_wait(&val, c + 1);
    }

    void unlock() {
        val = 0;
        futex_wake(&val, 1);
    }
};
