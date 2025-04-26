#include <stdio.h>
#include <pthread.h>

#define NUM_THREADS 4
#define COUNT_PER_THREAD 2500000
#define TARGET 10000000

// Shared counter variable and mutex for thread safety
long counter = 0;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void* count_to_target(void* arg) {
    int thread_id = *(int*)arg;
    long start = thread_id * COUNT_PER_THREAD;
    long end = start + COUNT_PER_THREAD;

    for (long i = start; i < end; i++) {
        pthread_mutex_lock(&mutex);
        counter++;
        pthread_mutex_unlock(&mutex);
    }
    return NULL;
}

int main() {
    pthread_t threads[NUM_THREADS];
    int thread_ids[NUM_THREADS];

    // Create threads
    for (int i = 0; i < NUM_THREADS; i++) {
        thread_ids[i] = i;
        if (pthread_create(&threads[i], NULL, count_to_target, &thread_ids[i]) != 0) {
            printf("Failed to create thread %d\n", i);
            return 1;
        }
    }

    // Wait for all threads to complete
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("Final counter value: %ld\n", counter);
    return 0;
}
