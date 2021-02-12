// 3. Why Do Futexes Work?

#include <bits/stdc++.h>

void futex_wake(int* futex_addr, int nwake);
void futex_wait(int* futex_addr, int val);

class Event {
   private:
    int val;

   public:
    Event() : val(0) {}

    void ev_signal() {
        ++val;
        futex_wake(&val, INT_MAX);
    }

    void ev_wait() {
        futex_wait(&val, val);
    }
};
