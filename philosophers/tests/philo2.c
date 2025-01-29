#include "../philo.h"

typedef struct {
    int counter;
    pthread_mutex_t lock;
} SharedData;

typedef struct {
    SharedData *shared;
    int iteration;
} ThreadArg;

void *increment(void *arg) {
    ThreadArg *threadArg = (ThreadArg *)arg;
    pthread_mutex_lock(&threadArg->shared->lock);
    threadArg->shared->counter++;
    printf("Counter: %d in the iteration: %d\n", threadArg->shared->counter, threadArg->iteration);
    pthread_mutex_unlock(&threadArg->shared->lock);
    return NULL;
}

int main() {
    pthread_t threads[5];
    SharedData shared = {0, PTHREAD_MUTEX_INITIALIZER};
    ThreadArg threadArgs[5];

    for(int i = 0; i < 5; i++) {
        threadArgs[i].shared = &shared;
        threadArgs[i].iteration = i + 1;
        pthread_create(&threads[i], NULL, increment, &threadArgs[i]);
    }

    for(int i = 0; i < 5; i++) {
        pthread_join(threads[i], NULL);
    }

    pthread_mutex_destroy(&shared.lock);
    return 0;
}