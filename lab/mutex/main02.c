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
static pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

static void *producer(__attribute__((unused)) void *arg) {
    unsigned seed = 17;
    struct timespec ts = {};

    for (int i = 0; i < ITEMS; i++) {
        // Simulate work for producing an item.
        ts.tv_nsec = 1e8 + (rand_r(&seed) % 9) * 1e8;
        nanosleep(&ts, NULL);

        // Produce next item, marking it as available.
        pthread_mutex_lock(&mutex);
        available++;
        pthread_mutex_unlock(&mutex);
    }
    return NULL;
}

static void *consumer(void *arg) {
    while (1) {
        pthread_mutex_lock(&mutex);

        if (item == ITEMS) {
            pthread_mutex_unlock(&mutex);
            break;  // All items consumed.
        }

        if (!available) {
            pthread_mutex_unlock(&mutex);
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
        pthread_mutex_unlock(&mutex);
        sleep(2);
    }
    return NULL;
}

int main(void) {
    pthread_t prod, consumers[CONSUMERS];
    char *names[] = {"A", "B", "C", "D", "E",
                     "F", "G", "H", "I", "J"};
                     
    for (int i = 0; i < CONSUMERS; i++) {
        pthread_create(&consumers[i], NULL, consumer, names[i]);
    }

    pthread_create(&prod, NULL, producer, "Producer");

    for (int i = 0; i < CONSUMERS; i++) {
        pthread_join(consumers[i], NULL);
    }
}