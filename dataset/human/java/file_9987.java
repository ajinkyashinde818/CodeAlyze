import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int M = sc.nextInt();
        int X = sc.nextInt();
        int[] C = new int[N];
        int[][] A = new int[N][M];
        for (int i=0;i<N;i++) {
            C[i] = sc.nextInt();
            for (int j=0;j<M;j++) {
                A[i][j] = sc.nextInt();
            }
        }

        int min = 2_000_000_000;
        for (int i=0;i<(1<<N);i++) {
            int[] arr = new int[N];
            int tmp = i;
            int cost = 0;
            int[] skill = new int[M];
            for (int j=0;j<N;j++) {
                arr[j] = tmp%2;
                tmp /= 2;
                if (arr[j] == 1) {
                    cost += C[j];
                    for (int k=0;k<M;k++) {
                        skill[k] += A[j][k];
                    }
                }
            }
            boolean flag = true;
            for (int j=0;j<M;j++) {
                if (skill[j] < X) flag = false;
            }
            if (flag) min = Math.min(min, cost);
        }
        // System.out.println(Arrays.deepToString(A));

        if (min == 2_000_000_000) System.out.println(-1);
        else System.out.println(min);
    }
}
