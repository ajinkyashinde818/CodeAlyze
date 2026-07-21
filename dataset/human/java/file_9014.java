import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        int[] a = new int[m];
        for (int i = 0 ; i < m ; i++) {
            a[i] = sc.nextInt();
        }
        int mod = 1000000007;
        long[] sum = new long[n + 2];
        sum[1] = 1;
        for (int i = 2 ; i < n + 2 ; i++) {
            sum[i] =   (long) sum[i - 1] + sum[i - 2];
            sum[i] %= mod;
        }
        if (m == 0) {
            System.out.println(sum[n + 1]);
            return;
        }
        for (int i = 0 ; i < m - 1 ; i++) {
            if (a[i + 1] - a[i] == 1) {
                System.out.println(0);
                return;
            }
        }
        long ans = 1l;
        int [] b = new int[m + 1];

        if (m == 1) {
            b[0] = a[0];
            b[1] = n - a[0];
        } else {
            b[0] = a[0];
            b[m] = n - a[m - 1];
            for (int i = 1 ; i < m ; i++) {
                if (a[i] - a[i - 1] == 0) {
                    b[i] = 1;
                } else {
                    b[i] = a[i] - a[i - 1] - 1;
                }
            }
        }
        for (int i = 0 ; i < m + 1 ; i++) {
            ans *= sum[b[i]] % mod;
            ans %= mod;
        }
        System.out.println(ans % mod);
    }

}
