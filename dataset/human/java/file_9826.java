import java.util.*;

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
        int ans = Integer.MAX_VALUE;

        int[] v = new int[M];
        for (int bit = 0; bit < (1 << N); ++bit) {
            Arrays.fill(v, 0);
            int cost = 0;
            for (int i = 0; i < N; i++) {
                if ((bit & (1 << i)) != 0) {
                    cost = cost + C[i];
                    for (int j = 0; j < M; j++) {
                        v[j] = v[j] + A[i][j];
                    }
                }
            }
            boolean ok = true;
            for (int i = 0; i < M; i++) {
                if (v[i] < X) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                ans = Math.min(ans, cost);
            }

        }
        System.out.println(ans<Integer.MAX_VALUE ? ans : -1);
        sc.close();

    }
}
