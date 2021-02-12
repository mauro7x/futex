#ifndef __X86__
#define __X86__

static inline int xchg(volatile int *addr, int newval) {
    int result;

    __asm__ volatile("xchgl %0, %1"
                     : "+m"(*addr), "=a"(result)
                     : "1"(newval)
                     : "cc");

    return result;
}

static inline void clear(volatile int *addr) {
    __asm__ volatile("movl $0, %0" : "+m"(*addr) :);
}

#endif // __X86__