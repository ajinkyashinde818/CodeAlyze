import java.util.Scanner;

public class Main {

    public static final int MOD = (int) (Math.pow(10, 9) + 7);

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = Integer.parseInt(sc.next());
        long[] a = new long[n];
        long sum = 0;
        for (int i = 0; i < n; i++) {
            long temp = Long.parseLong(sc.next());
            a[i] = temp;
            sum += temp;
        }
        long ans = Long.MAX_VALUE;
        long x = 0;
        for (int i = 0; i < n - 1; i++) {
            x += a[i];
            ans = Math.min(ans, Math.abs(sum - x - x));
        }
        System.out.println(ans);
    }
}
