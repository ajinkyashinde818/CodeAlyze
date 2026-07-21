import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] a = new int[n];
        long x = 0;
        long y = 0;
        long min;

        for (int i = 0; i < n; i++) {
            a[i] = sc.nextInt();
            y += a[i];
        }
        x = a[0];
        y -= a[0];
        min = Math.max(x, y) - Math.min(x, y);

        for (int i = 1; i < n - 1; i++) {
            x += a[i];
            y -= a[i];
            long tmp = Math.abs(x - y);
            if (min > tmp) {
                min = tmp;
            }
        }

        System.out.println(min);

    }
}
