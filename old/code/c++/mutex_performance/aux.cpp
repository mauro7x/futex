#include "aux.h"

int cmpxchg(std::atomic<bool>* atom, bool expected, bool desired) {
    bool* ep = &expected;
    std::atomic_compare_exchange_strong(atom, ep, desired);
    return *ep;
}

int cmpxchg(std::atomic<int>* atom, int expected, int desired) {
    int* ep = &expected;
    std::atomic_compare_exchange_strong(atom, ep, desired);
    return *ep;
}