using System;

class SyncCount
{
    static void Main(string[] args)
    {
        for (int i = 0; i <= 1000000000; i++)
        {
            if (i % 100000000 == 0)
            {
                Console.WriteLine($"Count reached: {i}");
            }
        }

        Console.WriteLine("Counting complete!");
    }
}
