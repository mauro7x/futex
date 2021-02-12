#define _POSIX_C_SOURCE 200809

#include <pthread.h>
#include <stdio.h>

static unsigned counter;
static pthread_spinlock_t lock;

static void *work(void *arg) {
    for (int i = 0; i < 1e7; i++) {
        pthread_spin_lock(&lock);
        counter++;
        pthread_spin_unlock(&lock);
    }
    printf("%s done\n", (char *) arg);
    return NULL;
}

int main(void) {
    pthread_t t1, t2;
    pthread_spin_init(&lock, PTHREAD_PROCESS_PRIVATE);

    pthread_create(&t1, NULL, work, "A");
    pthread_create(&t2, NULL, work, "B");

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    printf("main done (counter = %u)\n", counter);
}