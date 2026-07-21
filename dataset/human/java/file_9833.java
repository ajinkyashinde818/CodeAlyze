import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
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
        sc.close();

        long ans = Integer.MAX_VALUE;

        for (int t = 0; t < (1 << N); t++) {
            int[] target = new int[M];
            int cost = 0;
            for (int i = 0; i < N; i++) {
                if ((t >> i & 1) == 1) {
                    for (int j = 0; j < M; j++) {
                        target[j] += A[i][j];
                    }
                    cost += C[i];
                }
            }

            boolean flg = true;
            for (int j = 0; j < M; j++) {
                if (target[j] < X) {
                    flg = false;
                }
            }
            if (flg) {
                ans = Math.min(ans, cost);
            }
        }
        if (ans == Integer.MAX_VALUE) {
            ans = -1;
        }
        System.out.println(ans);
    }
}
