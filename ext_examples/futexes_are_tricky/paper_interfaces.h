#ifndef __PAPER_INTERFACES_H__
#define __PAPER_INTERFACES_H__

#include <bits/stdc++.h>

/* Firmas de los métodos esperados por el código del paper */

void futex_wake(int* futex_addr, int nwake);
void futex_wait(int* futex_addr, int val);
int atomic_inc(int& val);
int atomic_dec(int& val);
int cmpxchg(int& val, int old_v, int new_v);
int xchg(int& val, int new_v);

#endif  // __PAPER_INTERFACES_H__