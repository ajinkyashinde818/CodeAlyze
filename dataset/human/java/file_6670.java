import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        try (Scanner in = new Scanner(System.in)) {
            solve(in);
        }
    }

    private static void solve(Scanner in) {
        int N = in.nextInt();
        int[] A = new int[N];
        for (int i = 0; i < N; i++) {
            A[i] = in.nextInt();
        }
        System.out.println(ans(A) ? "YES" : "NO");
    }

    private static boolean ans(int[] A) {
        long N = A.length;
        if (N == 1) {
            return true;
        }

        long sum = 0;
        for (long a : A) {
            sum += a;
        }

        final long round = (N * (N + 1)) / 2L;
        if (sum % round > 0) {
            return false;
        }

        final int K = (int) (sum / round);

        long k = K;

        for (int i = 0; i < N; i++) {
            int d = A[(int) ((i + 1) % N)] - A[i];
            if (d > K) {
                return false;
            }
            if (d < K) {
                int yobun = (K - d);
                if (yobun % N > 0) {
                    return false;
                }
                k -= yobun / N;
            }
            if (k < 0) {
                return false;
            }
        }

        return true;
    }
}
