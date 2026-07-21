import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
	    // write your code here
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        long[] list = new long[n];
        long sum = 0;

        for (int i = 0; i < n; i++) {
            list[i] = sc.nextLong();
            sum += list[i];
        }
        
        long ans = Long.MAX_VALUE;
        long raccoon = sum;
        for (int i = 0; i < n - 1; i++) {
            raccoon -= list[i];
            ans = Math.min(ans, Math.abs(sum - raccoon * 2));
        }

        System.out.println(ans);
    }
}
