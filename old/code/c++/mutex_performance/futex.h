#ifndef __FUTEX_H__
#define __FUTEX_H__

#include <linux/futex.h>
#include <sys/syscall.h>
#include <sys/time.h>
#include <unistd.h>

/* Wrapper for futex(2) syscall */
int futex(int* uaddr, int futex_op, int val, const struct timespec* timeout,
          int* uaddr2, int val3);

/* Wrapper for futex_wait op */
int futex_wait(int* uaddr, int val, bool privative = false);

/* Wrapper for futex_wake_one op */
int futex_wake_one(int* uaddr, bool privative = false);

/* Wrapper for futex_wake_all op */
int futex_wake_all(int* uaddr, bool privative = false);

#endif  // __FUTEX_H__