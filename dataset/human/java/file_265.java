import java.util.Scanner;

public class Main {

    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        long[] a = new long[n];

        long cnt = 0;

        for (int i = 0; i < n; i++) {
            long num = sc.nextLong();
            a[i] = num;
            if (num < 0) {
                cnt++;
            }
        }

        sc.close();

        long ans = 0;

        if (cnt % 2 == 0) {
            for (int i = 0; i < n; i++) {
                ans += Math.abs(a[i]);
            }
        } else {
            long min = Long.MAX_VALUE;
            for (int i = 0; i < n; i++) {
                ans += Math.abs(a[i]);
                min = Math.min(Math.abs(a[i]), min);
            }
            ans -= 2 * min;
        }

        System.out.println(ans);
    }

}
