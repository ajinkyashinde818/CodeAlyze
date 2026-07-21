import java.io.InputStream;
import java.io.PrintStream;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.HashSet;
import java.util.List;
import java.util.Map;
import java.util.PriorityQueue;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) throws Exception {
        solve(System.in, System.out);
    }

    static void solve(InputStream is, PrintStream os) {
        // Your code here!
        Scanner scan = new Scanner(is);
        int N = scan.nextInt();
        int M = scan.nextInt();
        int X = scan.nextInt();

        int C[] = new int[N];
        int A[][] = new int[N][M];

        for (int i = 0; i < N; i++) {
            C[i] = scan.nextInt();
            for(int j = 0; j < M; j++) {
                A[i][j] = scan.nextInt();
            }
        }

        int ans = Integer.MAX_VALUE;

        for(int bit = 0; bit < (1 << N); bit++) {
            //初期化
            int sum[] = new int[M];
            int cost = 0;

            for (int i = 0; i < N; ++i) {
                if ((bit & (1<<i)) > 0) { // 列挙に i が含まれるか
                    cost += C[i];
                    for(int j = 0; j < M; j++) {
                        sum[j] += A[i][j];
                    }
                }
            }
            //判定
            boolean isSatisfy = true;
            for(int i = 0; i < M; i++) {
                if(sum[i] < X){
                    isSatisfy = false;
                    break;
                }
            }

            if(isSatisfy){
                ans = Math.min(ans, cost);
            }
        }

        if(ans == Integer.MAX_VALUE)
            os.println(-1);
        else
            os.println(ans);
    }


}
