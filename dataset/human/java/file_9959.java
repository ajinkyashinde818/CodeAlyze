import java.util.*;
public class Main {
    
    public static void main(String args[]){
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
        int ans = Integer.MAX_VALUE;
        for (int i = 0; i < (1<<N); i++) {
            int cost = 0;
            int[] understand = new int[M];
            // System.out.println(i);
            for (int j = 0; j < N; j++) {
                int buyj = (i>>j)&1;
                if(buyj == 1){
                    cost += C[j];
                    for (int k = 0; k < M; k++) {
                        understand[k] += A[j][k];
                    }
                }
            }
            // for (int j = 0; j < M; j++) {
            //     System.out.print(understand[j]);
            // }
            // System.out.println("");
            boolean res = true;
            for (int j = 0; j < M; j++) {
                if(understand[j] < X) res = false;
            }
            if(res) ans = Math.min(ans, cost);
        }
        if(ans==Integer.MAX_VALUE) System.out.println(-1);
        else System.out.println(ans);
    }
}
