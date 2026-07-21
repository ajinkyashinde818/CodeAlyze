import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        //input
        int d = scanner.nextInt();
        int g = scanner.nextInt()/100;
        int[] p = new int[d + 1];
        int[] c = new int[d + 1];
        for (int i = 1; i <= d; i++) {
            p[i] = scanner.nextInt();
            c[i] = scanner.nextInt()/100;
        }

        //dp table
        int[][] dp = new int[d + 1][1001];//dp[i][j]//i問目までをトータルでj問解いたスコア

        for (int i = 1; i <= d; i++) {//10種類の問題
            for (int j = 1; j <= 1000; j++) {//トータルで解くべき問題数
                for (int k = 0; k <= p[i] && k <= j; k++) {//問題数
                    int score = i * k;//スコア計算
                    if (k == p[i]) score += c[i];

                    score += dp[i - 1][j - k];//前の問題達を解いた総合スコア
                    if (score > dp[i][j]) dp[i][j] = score;//max更新
                }
            }
        }

        for (int i = 1; i <= 1000; i++) {
            if (dp[d][i] >= g) {//d問目までをi回で解いたスコア
                System.out.println(i);
                return;
            }
        }
    }
}
