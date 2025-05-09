#define _POSIX_C_SOURCE 200112L
#include <stdio.h>
#include <pthread.h>
#include <time.h>
#include <stdlib.h>

double count = 1000000000/4; // 1 billion divided by 4 for 4 threads
double steps = 5;

void* count_numbers(void* arg) 
{
    double iter = 0;
    struct timespec start_time, end_time;
    double time_taken;

    clock_gettime(CLOCK_MONOTONIC, &start_time);
    printf("Thread %ld started\n", (long)arg);

    for (long long i = 1; i <= count; i++) 
    {
        iter += 1;
        if (i % (long long)(count/steps) == 0) 
        {
            printf("Thread %ld: Counted to %lld\n", (long)arg, i);
        }
    }

    clock_gettime(CLOCK_MONOTONIC, &end_time);
    time_taken = (end_time.tv_sec - start_time.tv_sec) + 
                 (end_time.tv_nsec - start_time.tv_nsec) / 1000000000.0;

    printf("Thread %ld: Time taken to count from 1 to %.0f: %f seconds\n", 
           (long)arg, count, time_taken);
    
    return NULL;
}

int main() 
{
    pthread_t thread1, thread2, thread3, thread4;
    struct timespec start_time, end_time;
    double total_time;
    
    // Record the global start time
    clock_gettime(CLOCK_MONOTONIC, &start_time);
    
    // Creating new threads with thread number as argument
    pthread_create(&thread1, NULL, count_numbers, (void*)1);
    pthread_create(&thread2, NULL, count_numbers, (void*)2);
    pthread_create(&thread3, NULL, count_numbers, (void*)3);
    pthread_create(&thread4, NULL, count_numbers, (void*)4);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    pthread_join(thread3, NULL);
    pthread_join(thread4, NULL);
    
    // Record the global end time
    clock_gettime(CLOCK_MONOTONIC, &end_time);
    total_time = (end_time.tv_sec - start_time.tv_sec) + 
                 (end_time.tv_nsec - start_time.tv_nsec) / 1000000000.0;
    
    printf("All threads have finished counting.\n");
    printf("Total time: %f seconds\n", total_time);
    
    return 0;
}
