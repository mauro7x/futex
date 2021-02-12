#include "mutex_v0.h"

/** Mutex v0
 * std::mutex.
 */

Mutex_v0::Mutex_v0() {
    std::cout << "Implementación: std::mutex." << std::endl;
}

void Mutex_v0::lock() {
    m.lock();
}

void Mutex_v0::unlock() {
    m.unlock();
}

Mutex_v0::~Mutex_v0() {}