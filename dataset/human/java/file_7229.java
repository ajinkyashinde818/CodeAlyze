import java.util.Scanner;

public class Main {
    private static final int MOD = 1_000_000_007;
    private static final String YES = "Yes";
    private static final String NO = "No";

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int K = sc.nextInt();
        int N = sc.nextInt();
        int[] A = new int[N];
        for (int i=0; i<N; i++) {
            A[i] = sc.nextInt();
        }

        System.out.println(solve(K, N, A));
    }

    private static int solve(int K, int N, int[] A) {
        int count = 0;

        int max = 0;
        for (int i=0; i<N; i++) {
            int dist = 0;

            if (i==N-1) {
                dist = A[0] + K-A[N-1];
            } else {
                dist = A[i+1] - A[i];
            }

            max = Math.max(max, dist);
        }

        count = K - max;

        return count;
    }
}
