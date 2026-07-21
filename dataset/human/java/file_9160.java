import java.util.Arrays;
import java.util.Scanner;

public class Main {
    public static final int MOD = 1_000_000_007;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int N = sc.nextInt();
        int M = sc.nextInt();
        int[] a = new int[M];
        for (int i = 0; i < M; i++) {
            a[i] = sc.nextInt();
        }

        System.out.println(solveDP(N, M, a));
    }

    public static int solve(int N, int M, int[] a) {
        if (N == 1) return 1;

        int[] nlist = new int[N + 1];
        int aidx = 0;

        nlist[0] = 1;
        if (M != 0 && a[0] == 1) {
            nlist[1] = 0;
            aidx = 1;
        } else {
            nlist[1] = 1;
        }

        for (int i = 2; i <= N; i++) {
            if (aidx < M && a[aidx] == i) {
                nlist[i] = 0;
                aidx++;
            } else {
                nlist[i] = (nlist[i - 1] + nlist[i - 2]) % MOD;
            }
        }

        return nlist[N];
    }

    /**
     * 解説に従い，よりDPっぽく解く
     * @param N
     * @param M
     * @param a
     * @return
     */
    public static int solveDP(int N, int M, int[] a) {
        boolean[] valid = new boolean[N+1];
        int[] dp = new int[N+1];

        Arrays.fill(valid, true);
        for (int i=0; i<M; i++) {
            valid[a[i]] = false;
        }
        dp[0] = 1;
        for (int cur=0; cur<N; cur++) {
            for (int next=cur+1; next<=Math.min(N, cur+2); next++) {
                if (valid[next]) {
                    dp[next] += dp[cur];
                    dp[next] %= MOD;
                }
            }
        }

        return dp[N];
    }
}
