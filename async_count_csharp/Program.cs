using System;
using System.Diagnostics;
using System.Threading;
using System.Threading.Tasks;

class ParallelCount
{
    static void Main(string[] args)
    {
        Stopwatch stopwatch = new Stopwatch();
        stopwatch.Start();

        // Set the degree of parallelism to 4 cores
        ParallelOptions parallelOptions = new ParallelOptions
        {
            MaxDegreeOfParallelism = 4
        };

        // Use a thread-safe variable to track total count across all threads
        object lockObject = new object();

        // Divide the counting range into chunks
        const long totalCount = 1_000_000_000;
        const int chunks = 4;
        long chunkSize = totalCount / chunks;

        Parallel.For(0, chunks, parallelOptions, chunkIndex =>
        {
            long start = chunkIndex * chunkSize;
            long end = (chunkIndex == chunks - 1) ? totalCount : (chunkIndex + 1) * chunkSize - 1;
            
            for (long i = start; i <= end; i++)
            {
                if (i % 100_000_000 == 0)
                {
                    lock (lockObject)
                    {
                        Console.WriteLine($"Count reached: {i}");
                    }
                }
            }
        });

        stopwatch.Stop();
        Console.WriteLine("Counting complete!");
        Console.WriteLine($"Time elapsed: {stopwatch.Elapsed}");
    }
}
