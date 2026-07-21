import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Main main = new Main();
        main.solve();
    }
    public void solve() {
        Scanner scan = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
        int D = scan.nextInt();
        int G = scan.nextInt();
        Problem[] list = new Problem[D];
        for (int i = 0; i < D; i++) {
            Problem p = new Problem();
            int score = (i + 1) * 100;
            int count = scan.nextInt();
            int bonus = scan.nextInt();
            p.score = score;
            p.count = count;
            p.bonus = bonus;
            list[i] = p;
        }
        int[][] dp = new int[D+1][G+2000001];
        for (int i = 0; i <= D; i++) {
            Arrays.fill(dp[i], Integer.MAX_VALUE);
        }
        dp[0][0] = 0;
        for (int i = 0; i < D; i++) {
            for (int j = 0; j <= G+2000000; j++) {
                if (dp[i][j] == Integer.MAX_VALUE) {
                    continue;
                }
                Problem p = list[i];
                for (int k = 0; k <= p.count; k++) {
                    if (k < p.count) {
                        if (G + 2000000 < j + p.score * k) {
                            continue;
                        }
                        dp[i+1][j + p.score * k] = Math.min(dp[i+1][j + p.score * k], dp[i][j] + k);
                    } else {
                        if (G + 2000000 < j + p.score * k + p.bonus) {
                            continue;
                        }
                        dp[i+1][j + p.score * k + p.bonus] = Math.min(dp[i+1][j + p.score * k + p.bonus], dp[i][j] + k);
                    }
                }
            }
        }
        int answer = Integer.MAX_VALUE;
        for (int i = G; i <= G + 2000000; i++) {
            answer = Math.min(answer, dp[D][i]);
        }
        System.out.println(answer);
    }
    class Problem {
        int score;
        int count;
        int bonus;
    }
}
