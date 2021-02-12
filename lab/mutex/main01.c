// gcc -O2 -std=c99 consumers.c -lpthread -DCONSUMERS=<1|2|3|4>

#define _POSIX_C_SOURCE 200809

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>  // rand_r
#include <time.h>    // nanosleep
#include <unistd.h>  // sleep

#ifndef ITEMS
#define ITEMS 15
#endif

#ifndef CONSUMERS
#define CONSUMERS 2
#endif

static unsigned item;
static unsigned available;
static pthread_spinlock_t lock;

static void *producer(__attribute__((unused)) void *arg) {
    unsigned seed = 17;
    struct timespec ts = {};

    for (int i = 0; i < ITEMS; i++) {
        // Simulate work for producing an item.
        ts.tv_nsec = 1e8 + (rand_r(&seed) % 9) * 1e8;
        nanosleep(&ts, NULL);

        // Produce next item, marking it as available.
        pthread_spin_lock(&lock);
        available++;
        pthread_spin_unlock(&lock);
    }
    return NULL;
}

static void *consumer(void *arg) {
    while (1) {
        pthread_spin_lock(&lock);

        if (item == ITEMS) {
            pthread_spin_unlock(&lock);
            break;  // All items consumed.
        }

        if (!available) {
            pthread_spin_unlock(&lock);
#ifdef RESPIN_WAIT
            sleep(1);
#endif
            continue;
        }

        // Simulate getting the item
        //printf("%s: consumed item %u\n", (char *) arg, ++item);
        ++item;
        available--;

        // Release the lock and simulate some work.
        pthread_spin_unlock(&lock);
        sleep(2);
    }
    return NULL;
}

int main(void) {
    pthread_t prod, consumers[CONSUMERS];
    char *names[] = {"A", "B", "C", "D", "E",
                     "F", "G", "H", "I", "J"};

    pthread_spin_init(&lock, PTHREAD_PROCESS_PRIVATE);

    for (int i = 0; i < CONSUMERS; i++) {
        pthread_create(&consumers[i], NULL, consumer, names[i]);
    }

    pthread_create(&prod, NULL, producer, "Producer");

    for (int i = 0; i < CONSUMERS; i++) {
        pthread_join(consumers[i], NULL);
    }
}