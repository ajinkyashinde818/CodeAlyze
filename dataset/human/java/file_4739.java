import java.util.Scanner;

public class Main {
    private static final int MOD = 1_000_000_007;
    private static final String YES = "Yes";
    private static final String NO = "No";

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        String N = sc.next();
        System.out.println(solveDP(N));
    }

    private static long solve(String N) {
        long count = 0;

        int[] convert = {
                0, 1, 2, 3 ,4, 5, 4, 3, 2, 1
        };

        int keta = 0;
        for (int i=0; i<N.length(); i++) {
            int val = N.charAt(N.length()-i-1) - '0';

            if (val+keta == 5 && i != N.length()-1) {
                int nextVal = N.charAt(N.length()-i-2) - '0';
                if (nextVal >= 5) {
                    keta = 1;
                    count += 5;

                    continue;
                }
            }

            count += convert[(val+keta)%10];
            if (val+keta >= 6) {
                keta = 1;
            } else {
                keta = 0;
            }
            // System.err.println("val=" + val + ", keta=" + keta + ", count=" + count);
        }
        if (keta == 1) {
            count += 1;
        }

        return count;
    }

    private static long solveDP(String N) {
        // dp[1桁上の紙幣でまとめて払う][i桁目まで]
        int[][] dp = new int[2][N.length()+2];
        dp[0][0] = 0;
        dp[1][0] = Integer.MAX_VALUE/2;

        int len = N.length();
        N = '0' + N;
        for (int i=0; i<=len; i++) {
            int val = N.charAt(N.length() - i - 1) - '0';

            dp[0][i+1] = Math.min(dp[0][i] + val,      dp[1][i] + val+1);
            dp[1][i+1] = Math.min(dp[0][i] + 10 - val, dp[1][i] + 10 - (val+1));
        }

        return dp[0][len+1];
    }
}
