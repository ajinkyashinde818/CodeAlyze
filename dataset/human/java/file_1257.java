import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner std = new Scanner(System.in);
        int n = std.nextInt();
        int[] as = new int[n];
        long[] ldp = new long[n];
        long[] rdp = new long[n];
        for (int i = 0; i < n; i++) {
            as[i] = std.nextInt();
        }

        ldp[0] = as[0];
        for (int i = 1; i < n; i++) {
            ldp[i] = as[i] + ldp[i - 1];
        }

        long min = Long.MAX_VALUE;
        int right = n - 1;
        int left = 0;

        for (int i = 0; i < n - 1; i++) {
            long lv = ldp[i];
            long rv;
            if (i > 0) {
                rv = ldp[right] - ldp[i];
            } else {
                rv = ldp[right] - ldp[i];
            }
            long diff = Math.abs(lv - rv);
            min = Math.min(diff, min);
        }

        System.out.println(min);
    }
}
