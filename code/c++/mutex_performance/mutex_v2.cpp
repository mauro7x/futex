#include "mutex_v2.h"

/** Mutex v2
 * Primer acercamiento a futex(2). Ineficiente por la cantidad de llamados a
 * futex_wake.
 */

Mutex_v2::Mutex_v2() : taken(false) {
    std::cout << "Implementación: futex_wait y futex_wake_one (boolean)"
              << std::endl;
}

void Mutex_v2::lock() {
    while (cmpxchg(&taken, false, true)) {
        futex_wait((int*)&taken, true, true);
    }
}

void Mutex_v2::unlock() {
    taken.store(false);
    // Notar que esto es terriblemente ineficiente. Se hace una syscall cada vez
    // que haya un unlock, incluso cuando no hay threads esperando. Esto hace de
    // esta implementación, inusable.
    futex_wake_one((int*)&taken, true);
}

Mutex_v2::~Mutex_v2() {}