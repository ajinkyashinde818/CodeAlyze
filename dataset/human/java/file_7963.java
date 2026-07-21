import java.util.Arrays;
import java.util.Scanner;

public class Main {
    final double EPS = 1.0e-10;
    final int INF = 1 << 28;

    void run() {
        Scanner sc = new Scanner(System.in);
        int MAX = 1120;
        boolean[] isPrime = new boolean[MAX];
        int[] primes = new int[187];
        Arrays.fill(isPrime, true);
        int idx = 0;
        for (int i = 2; i < MAX; i++) {
            if (isPrime[i]) {
                primes[idx++] = i;
                for (int j = i * 2; j < MAX; j += i)
                    isPrime[j] = false;
            }
        }
        int dp[][][] = new int[187][MAX + 1][15];
        for (int i = 0; i < 187; i++) {
            for (int j = 0; j < MAX + 1; j++) {
                Arrays.fill(dp[i][j], 0);
                if (j == primes[i])
                    dp[i][j][1] = 1;
            }
        }
        for (int i = 0; i < 186; i++) {
            for (int j = 0; j < MAX + 1; j++) {
                for (int k = 1; k <= 14; k++) {
                    dp[i + 1][j][k] += dp[i][j][k];
                    if (j - primes[i+1] >= 0) {
                        dp[i + 1][j][k] += dp[i][j - primes[i+1]][k - 1];
                    }
                }
            }
        }
        while (true) {
            int n = sc.nextInt();
            int k = sc.nextInt();
            if ((n | k) == 0)
                break;
            System.out.println(dp[186][n][k]);
        }

    }

    public static void main(String[] args) {
        new Main().run();
    }
}
