import static java.lang.Math.*;

import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        long[] sum = new long[n];
        sum[0] = sc.nextLong();
        for (int i = 1; i < n; i++) {
            sum[i] = sc.nextLong() + sum[i-1];
        }
        long ans = Long.MAX_VALUE;
        for (int i = 0; i < n - 1; i++) {
            ans = min(ans, abs(sum[n-1] - sum[i] *2));
        }


        System.out.println(ans);
        sc.close();
    }
}
