#include "mutex_v1.h"

/** Mutex v1
 * Utilizando busy-waiting y atomic_compare_exchange_strong.
 */

Mutex_v1::Mutex_v1() : taken(false) {
    std::cout
        << "Implementación: busy-waiting sobre atomic_compare_exchange_strong."
        << std::endl;
}

void Mutex_v1::lock() {
    while (cmpxchg(&taken, false, true)) {
        ;
    }
}

void Mutex_v1::unlock() {
    taken.store(false);
}

Mutex_v1::~Mutex_v1() {}