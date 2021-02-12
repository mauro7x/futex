// 6. Mutex, Take 3

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