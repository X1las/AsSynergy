#include <stdio.h>
#include <time.h>

int main() 
{
    clock_t start_time, end_time;
    double time_taken;
    double count = 0;

    start_time = clock(); // Record start time

    for (long long i = 1; i <= 20000000000; i++) {
        count += 1; // Increment count
        if (i % 2000000000 == 0) { // Print every 100 million
            printf("Counted to %lld\n", i);
        }
    }

    end_time = clock(); // Record end time

    time_taken = ((double)(end_time - start_time)) / CLOCKS_PER_SEC; // Calculate elapsed time

    printf("Time taken to count from 1 to a billion: %f seconds\n", time_taken);

    return 0;
}
