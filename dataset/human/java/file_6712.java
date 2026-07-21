import java.util.Scanner;
import java.util.stream.IntStream;

public class Main {

    public static void main(String[] args) {
        final Scanner sc = new Scanner(System.in);

        final int k = sc.nextInt();
        final int n = sc.nextInt();

        final int[] d = new int[n];
        final int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = sc.nextInt();
        }

        for (int i = 0; i < n-1; i++) {
            d[i] = a[i+1] - a[i];
        }

        d[n-1] = k + a[0] - a[n-1];

        System.out.println(IntStream.of(d).sum() - IntStream.of(d).max().getAsInt());
    }
}
