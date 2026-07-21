import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        try (Scanner in = new Scanner(System.in)) {
            int N = in.nextInt();
            long[] a = new long[N];
            for (int i = 0; i < N; i++) {
                a[i] = in.nextInt();
            }

            long[] cumsum = new long[N];
            for (int i = 0; i < N; i++) {
                cumsum[i] = (i - 1 < 0 ? 0 : cumsum[i - 1]) + a[i];
            }

            long min = (long) 1e18;
            for (int i = 0; i < N - 1; i++) {
                long snuke = cumsum[i];
                long other = cumsum[N - 1] - cumsum[i];
                min = Math.min(min, Math.abs(snuke - other));
            }

            System.out.println(min);
        }
    }
}
