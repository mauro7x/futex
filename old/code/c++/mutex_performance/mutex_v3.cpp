#include "mutex_v3.h"

/** Mutex v3
 * Segundo acercamiento a futex(2). Ahora se utiliza un int en vez de un
 * booleano para poder identificar cuando tenemos otros hilos esperando y ante
 * un unlock, sólo llamar a futex_wake si es necesario.
 */

Mutex_v3::Mutex_v3() : status(0) {
    std::cout << "Implementación: futex_wait y futex_wake_one (int)"
              << std::endl;
}

void Mutex_v3::lock() {
    int c = cmpxchg(&status, 0, 1);
    if (c != 0) {
        do {
            if (c == 2 || cmpxchg(&status, 1, 2) != 0) {
                futex_wait((int*)&status, 2, true);
            }
            // Lo setteamos en 2 porque no podemos saber si hay
            // otro hilo esperando en este mismo lugar.
        } while ((c = cmpxchg(&status, 0, 2)) != 0);
    }
}

void Mutex_v3::unlock() {
    if (status.fetch_sub(1) != 1) {
        status.store(0);
        futex_wake_one((int*)&status, true);
    }
}

Mutex_v3::~Mutex_v3() {}