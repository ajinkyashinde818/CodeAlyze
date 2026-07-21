import java.util.Scanner;

public class Main {
     public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        int M = scanner.nextInt();
        int X = scanner.nextInt();

        int [][] A = new int[12][12];
        int [] C = new int[N];

         int ans = 1000000000;

        for (int i = 0; i < N; i++) {
            C[i] = scanner.nextInt();
            for (int j = 0; j < M; j++) {
                A[i][j] = scanner.nextInt();
            }
        }

        for (int i = 0; i < (1 << N); i++) {
            int cost = 0;
            int [] D = new int[M];
            for (int j = 0; j < N; j++) {
                if (((i >> j) & 1) != 0) {
                    cost += C[j];
                    for (int k = 0; k < M; k++) {
                        D[k] += A[j][k];
                    }
                }
            }
            boolean ok = true;
            for (int k = 0; k < M; k++) {
                if (D[k] < X) {
                    ok = false;
                }
            }
            if (ok) {
                ans = Math.min(ans, cost);
            }
        }
        if (ans == 1000000000) {
            System.out.println(-1);
        } else  {
            System.out.println(ans);
        }
    }
}
