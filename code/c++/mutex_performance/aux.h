#ifndef __AUX_H__
#define __AUX_H__

#include <atomic>

/* Wrappers for atomic_compare_exchange_strong */
int cmpxchg(std::atomic<bool>* atom, bool expected, bool desired);
int cmpxchg(std::atomic<int>* atom, int expected, int desired);

#endif  // __AUX_H__