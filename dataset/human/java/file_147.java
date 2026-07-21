import java.util.*;
public class Main {
    public static void main(String[] args) {
        /* 入力 */
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        //aひとつひとつは10**9以下だが、足し合わせるとintの最大値を超えてしまうので、a自体longで宣言しておく
        long a[] = new long[N];
        for (int i = 0; i<N; i++) {
            a[i] = sc.nextLong();
        }
        /* 
        DP配列宣言 dp[i][1] = dp[i][+], dp[i][0] = dp[i][-] と定義する。
        dp[i]は、a[i]までの部分列に対する答えを表し、dp[0]は定義しない（使わない）ことにする。
         */
        long dp[][] = new long[N][2];
        //dp[1]を初期化する。
        if (a[1] >= 0) {
            dp[1][1] = a[0] + a[1];
            dp[1][0] = -(a[0] + a[1]);
        } else {
            dp[1][1] = -(a[0] + a[1]);
            dp[1][0] = a[0] + a[1];
        }
        //dp[2]以降を漸化式で求める。
        for (int i = 2; i < N; i++) {
            if (a[i] >= 0) {
                dp[i][1] = Math.max(dp[i-1][1] + a[i], dp[i-1][0] + a[i]);
                dp[i][0] = Math.max(dp[i-1][1] - 2*Math.abs(a[i-1]) - a[i],
                dp[i-1][0] + 2*Math.abs(a[i-1]) - a[i]);
            } else {
                dp[i][1] = Math.max(dp[i-1][1] - 2*Math.abs(a[i-1]) + Math.abs(a[i]),
                dp[i-1][0] + 2*Math.abs(a[i-1]) + Math.abs(a[i]));
                dp[i][0] = Math.max(dp[i-1][1] + a[i], dp[i-1][0] + a[i]);
            }
        }
        //最終的な解は、元の数列a全体を使って、右端が+になる最適解と、右端が-になる最適解のうちの、より大きいほう。
        long answer = Math.max(dp[N-1][1],dp[N-1][0]);
        System.out.println(answer);
    }
}
