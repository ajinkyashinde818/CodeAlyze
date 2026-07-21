import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {
        // Your code here!
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        long[] cumsum = new long[n + 1];
        for (int i = 0; i < n; i++) {
            int num = sc.nextInt();
            cumsum[i + 1] = cumsum[i] + num; 
        }
        
        long sum = cumsum[n];
        long min = Long.MAX_VALUE;
        for (int i = 1; i < n; i++) {
            min = Math.min(min, Math.abs((sum - cumsum[i]) - cumsum[i]));
        }
        
        System.out.println(min);
    }
}
