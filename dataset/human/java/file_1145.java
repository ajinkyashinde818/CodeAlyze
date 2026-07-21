import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        long[] a = new long [n];
        long total = 0l;
        for (int i = 0; i < a.length; i++) {
            a[i] = sc.nextLong();
            total += a[i];
        }
        long ans = Long.MAX_VALUE;
        long total2 = 0l;
        for (int i = 0; i < a.length - 1; i++) {
            total2 += a[i];
            total -= a[i];
            ans = Math.min(ans, Math.abs(total2 - total));
        }
        System.out.println(ans);
    }
}
