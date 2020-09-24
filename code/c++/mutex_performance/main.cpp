#include <iostream>
#include <list>
#include <thread>

#include "mutex.h"

#ifndef MUTEX_V
#define MUTEX_V 0
#endif

#ifndef N_THREADS
#define N_THREADS 3
#endif

#ifndef SUM_PER_THREAD
#define SUM_PER_THREAD 10000000
#endif

#define EXPECTED_RESULT ((N_THREADS) * (SUM_PER_THREAD))

void threadfunc(int* val, Mutex* m) {
    for (int i = 0; i < SUM_PER_THREAD; i++) {
        m->lock();
        (*val)++;
        m->unlock();
    }
}

int main(int argc, const char* argv[]) {
    Mutex m(MUTEX_V);
    int resultado = 0;
    std::list<std::thread*> threads;

    for (int i = 0; i < N_THREADS; i++) {
        std::thread* t = new std::thread(threadfunc, &resultado, &m);
        threads.push_back(t);
    }

    for (auto thread : threads) {
        thread->join();
        delete thread;
    }

    if (resultado != EXPECTED_RESULT) {
        std::cout << "RESULTADO INCORRECTO." << std::endl;
    }
    return 0;
}