import java.io.BufferedInputStream;
import java.util.Scanner;

public class Main {
    private static Scanner sc = new Scanner(new BufferedInputStream(System.in));

    static int N, M, X;
    static int[] prices = new int[12];
    static int[][] map = new int[12][12];
    static int[] cur_goal = new int[12];
    static int cur_cost = 0;
    static int mincost = Integer.MAX_VALUE;


    static void dfs(int i) {
        if (i == N) {
            return;
        }

        cur_cost += prices[i];
        for (int j = 0; j < M; j++) {
            cur_goal[j] += map[i][j];
        }

        boolean suc = true;
        for (int j = 0; j < M; j++) {
            if (cur_goal[j] < X) {
                suc = false;
                break;
            }
        }

        if (suc && cur_cost < mincost) {
            mincost = cur_cost;
        }

        dfs(i + 1);
        cur_cost -= prices[i];
        for (int j = 0; j < M; j++) {
            cur_goal[j] -= map[i][j];
        }
        dfs(i + 1);
    }

    public static void main(String[] args) {
        N = sc.nextInt();
        M = sc.nextInt();
        X = sc.nextInt();
        for (int i = 0; i < N; i++) {
            prices[i] = sc.nextInt();
            for (int j = 0; j < M; j++) {
                map[i][j] = sc.nextInt();
            }
        }
        dfs(0);
        if (mincost == Integer.MAX_VALUE) {
            System.out.println(-1);
        } else {
            System.out.println(mincost);
        }

    }
}
