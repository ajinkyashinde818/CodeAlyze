import java.util.*;
import java.lang.*;


public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        long sum[] = new long[n];
        sum[0] = sc.nextLong();
        for (int i = 1; i < n; i++) {
            sum[i] = sum[i - 1] + sc.nextLong();
        }
        long min = 10000000000l;
        for (int i = 0; i < n - 1; i++) {
            min = Math.min(min, Math.abs(sum[n - 1] - 2 * sum[i]));
        }
        System.out.println(min);
    }
}
