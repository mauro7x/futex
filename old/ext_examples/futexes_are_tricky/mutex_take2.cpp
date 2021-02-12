// 4. Mutex, Take 2

#include "paper_interfaces.h"

class Mutex2 {
   private:
    int val;

   public:
    Mutex2() : val(0) {}

    void lock() {
        int c;
        if ((c = cmpxchg(val, 0, 1)) != 0)
            do {
                if (c == 2 || cmpxchg(val, 1, 2) != 0)
                    futex_wait(&val, 2);
            } while ((c = cmpxchg(val, 0, 2)) != 0);
    }

    void unlock() {
        if (atomic_dec(val) != 1) {
            val = 0;
            futex_wake(&val, 1);
        }
    }
};
