#include "futex.h"

int futex(int* uaddr, int futex_op, int val, const struct timespec* timeout,
          int* uaddr2, int val3) {
    return syscall(SYS_futex, uaddr, futex_op, val, timeout, uaddr2, val3);
}

int futex_wait(int* uaddr, int val, bool privative) {
    return syscall(SYS_futex, uaddr,
                   privative ? FUTEX_WAIT_PRIVATE : FUTEX_WAIT, val, 0, 0, 0);
}

int futex_wake_one(int* uaddr, bool privative) {
    return syscall(SYS_futex, uaddr,
                   privative ? FUTEX_WAKE_PRIVATE : FUTEX_WAKE, 1, 0, 0, 0);
}

int futex_wake_all(int* uaddr, bool privative) {
    return syscall(SYS_futex, uaddr,
                   privative ? FUTEX_WAKE_PRIVATE : FUTEX_WAKE, __INT_MAX__, 0,
                   0, 0);
}