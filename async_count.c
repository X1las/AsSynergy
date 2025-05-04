#include <stdio.h>
#include <pthread.h>
#include <time.h>

double count = 1000000000/4; // 1 billion divided by 4 for 4 threads
double steps = 10;

void count_numbers() 
{
    double iter = 0;

    clock_t start_time, end_time;
    double time_taken;

    start_time = clock(); // Record start time

    for (long long i = 1; i <= count; i++) 
    {
        iter += 1;
        if (i % (long long)(count/steps) == 0) 
        {
            printf("Counted to %lld\n", i);
        }
    }

    end_time = clock(); // Record end time
    time_taken = ((double)(end_time - start_time)) / CLOCKS_PER_SEC; // Calculate elapsed time

    printf("Time taken to count from 1 to a billion: %f seconds\n", time_taken);
}

int main() 
{
    // Create a pthread_t variable to store
    // thread ID
    pthread_t thread1;
    pthread_t thread2;
    pthread_t thread3;
    pthread_t thread4;
    
    // Creating a new thread. 
    pthread_create(&thread1, NULL, count_numbers, NULL);
    pthread_create(&thread2, NULL, count_numbers, NULL);
    pthread_create(&thread3, NULL, count_numbers, NULL);
    pthread_create(&thread4, NULL, count_numbers, NULL);

    pthread_join(thread1, NULL); // Wait for thread 1 to finish
    pthread_join(thread2, NULL); // Wait for thread 2 to finish
    pthread_join(thread3, NULL); // Wait for thread 3 to finish
    pthread_join(thread4, NULL); // Wait for thread 4 to finish
    printf("All threads have finished counting.\n");
}
