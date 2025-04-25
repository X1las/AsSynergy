public class sync_count {
    public static void main(String[] args) {
        System.out.println("Starting to count from 1 to 1 billion...");
        
        // Record start time
        long startTime = System.currentTimeMillis();
        
        // Count from 1 to 1 billion
        long count = 0;
        for (long i = 1; i <= 1000000000; i++) {
            count++;
            
            // Output message every 100 million iterations
            if (count % 100000000 == 0) {
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
