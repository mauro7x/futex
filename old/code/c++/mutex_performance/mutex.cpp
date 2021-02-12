#include "mutex.h"

// Wrapper RAII para las distintas versiones implementadas

Mutex::Mutex(const int version) : m(nullptr) {
    switch (version) {
        case 0:
            this->m = new Mutex_v0;
            break;

        case 1:
            this->m = new Mutex_v1;
            break;

        case 2:
            this->m = new Mutex_v2;
            break;

        case 3:
            this->m = new Mutex_v3;
            break;

        default:
            break;
    }
}

void Mutex::lock() {
    m->lock();
}

void Mutex::unlock() {
    m->unlock();
}

Mutex::~Mutex() {
    if (m != nullptr) {
        delete m;
        m = nullptr;
    }
}