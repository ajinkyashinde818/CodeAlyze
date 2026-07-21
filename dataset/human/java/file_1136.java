import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        long[] a = new long[n];
        for (int i = 0 ; i < n ; i++) {
            a[i] = sc.nextLong();
        }
        long l = a[0];
        long r = 0;
        for (int i = 1 ; i < n ; i++) {
            r += a[i];
        }

        long min = Math.abs(l - r);
        for (int i = 1 ; i < n - 1 ; i++) {
            l += a[i];
            r -= a[i];
            min = Math.min(min, Math.abs(l - r));
        }
        System.out.println(min);

    }

}
