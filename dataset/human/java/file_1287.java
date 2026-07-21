import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();

        long total = 0;
        long a[] = new long[n];
        for (int i = 0; i < n; i++) {
            a[i] = in.nextInt();
            total += a[i];
        }

        long former = 0;
        long min = Long.MAX_VALUE;
        for (int i = 0; i < n - 1; i++) {
            former += a[i];
            min = Math.min(min, Math.abs(total - 2 * former));
        }

        System.out.println(min);
    }
}
