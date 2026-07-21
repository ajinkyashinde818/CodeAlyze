import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        try (Scanner in = new Scanner(System.in)) {
            int N = in.nextInt();
            int M = in.nextInt();
            int[] a = new int[M];
            for (int i = 0; i < M; i++) {
                a[i] = in.nextInt();
            }
            final long mod = 1000000007;

            boolean[] isBroken = new boolean[N + 1 + 2];
            for (int i = 0; i < M; i++) {
                isBroken[a[i]] = true;
            }
            isBroken[N + 1] = true;
            isBroken[N + 2] = true;

            long[] stair = new long[N + 1];
            stair[0] = 1;
            for (int i = 0; i < N + 1; i++) {
                if (!isBroken[i + 1]) {
                    stair[i + 1] += stair[i];
                    stair[i + 1] %= mod;
                }
                if (!isBroken[i + 2]) {
                    stair[i + 2] += stair[i];
                    stair[i + 2] %= mod;
                }
            }
            System.out.println(stair[N]);
        }
    }
}
