#ifndef __GENERIC_MUTEX_H__
#define __GENERIC_MUTEX_H__

#include <iostream>

class GenericMutex {
   public:
    GenericMutex() {}
    GenericMutex(const GenericMutex& copiable) = delete;
    GenericMutex& operator=(const GenericMutex& copiable) = delete;
    GenericMutex(GenericMutex&& movible) = delete;
    GenericMutex& operator=(GenericMutex&& movible) = delete;

    virtual void lock() = 0;
    virtual void unlock() = 0;

    virtual ~GenericMutex() {}
};

#endif  // __GENERIC_MUTEX_H__