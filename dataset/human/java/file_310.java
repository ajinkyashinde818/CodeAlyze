import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        long[] a = new long[n];

        long total = 0;
        long min = Integer.MAX_VALUE;
        int minCnt = 0;
        for (int i = 0; i < n; i++) {
            a[i] = sc.nextLong();
            if (a[i] < 0)
                minCnt++;

            total += Math.abs(a[i]);
            min = Math.min(min, Math.abs(a[i]));
        }

        if (minCnt % 2 == 1) {
            total -= min * 2;
        }

        System.out.println(total);
    }
}
