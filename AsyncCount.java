public class AsyncCount extends Thread
{
    public static void main(String[] args) 
    {
        AsyncCount thread = new AsyncCount();
          thread.start();

        AsyncCount thread2 = new AsyncCount();
          thread2.start();

        AsyncCount thread3 = new AsyncCount();
          thread3.start();

        AsyncCount thread4 = new AsyncCount();
          thread4.start();
    }

    public void run() 
    {
        System.out.println("Starting to count from 1 to 1 quarter billion...");
        
        // Record start time
        long startTime = System.currentTimeMillis();
        
        // Count from 1 to 1 billion
        long count = 0;
        for (long i = 1; i <= 1000000000/4; i++) {
            count++;
            
            // Output message every 100 million iterations
            if (count % 50000000 == 0) 
            {
                System.out.println("Reached " + i);
            }
        }
        
        // Record end time
        long endTime = System.currentTimeMillis();
        
        // Calculate elapsed time
        long elapsedTime = endTime - startTime;
        
        System.out.println("Counting complete. Final value: " + count);
        System.out.println("Time elapsed: " + (elapsedTime / 1000.0) + " seconds");
    }
}