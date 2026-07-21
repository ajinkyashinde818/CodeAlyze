import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        try (Scanner sc = new Scanner(System.in)) {
            int N = sc.nextInt();
            int M = sc.nextInt();
            int X = sc.nextInt();
            int[] C = new int[N];
            int[][] A = new int[N][M];
            for (int i = 0; i < N; i++) {
                C[i] = sc.nextInt();
                for (int j = 0; j < M; j++) {
                    A[i][j] = sc.nextInt();
                }
            }

            int inf = (int) 1e9;
            int min = inf;
            maskLoop: for (int mask = 0; mask < (1 << N); mask++) {
                int[] sum = new int[M];
                for (int i = 0; i < N; i++) {
                    if ((mask & (1 << i)) == 0) {
                        continue;
                    }
                    for (int j = 0; j < M; j++) {
                        sum[j] += A[i][j];
                    }
                }
                for (int j = 0; j < M; j++) {
                    if (sum[j] < X) {
                        continue maskLoop;
                    }
                }

                int cost = 0;
                for (int i = 0; i < N; i++) {
                    if ((mask & (1 << i)) == 0) {
                        continue;
                    }
                    cost += C[i];
                }
                if (cost < min) {
                    min = cost;
                }
            }

            System.out.println(min == inf ? -1 : min);
        }
    }

    private static boolean isValid(int mask, int[][] a, int x) {
        return false;
    }
}
