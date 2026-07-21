import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int N = scanner.nextInt();
        int M = scanner.nextInt();
        int X = scanner.nextInt();

        int[] C = new int[N];
        int[][] A = new int[N][M];

        for (int i = 0; i < N; i++) {
            C[i] = scanner.nextInt();
            for (int j = 0; j < M; j++) {
                A[i][j] = scanner.nextInt();
            }
        }

        int minCost = -1;
        for (int i = 0 ; i < (1 << N) ; i++) {
            int cost = 0;
            int[] skills = new int[M];
            for (int j = 0 ; j < N ; j++) {
                if (((i >> j) & 1) == 1) {
                    cost += C[j];
                    for (int k = 0 ; k < M ; k++) {
                        skills[k] += A[j][k];
                    }
                }
            }

            boolean flag = true;
            for (int k = 0 ; k < M ; k++) {
                if (skills[k] < X) flag = false;
            }

            if (flag) {
                if (minCost == -1) {
                    minCost = cost;
                } else  {
                    minCost = Math.min(minCost, cost);
                }
            }
        }
        System.out.println(minCost);
    }
}
