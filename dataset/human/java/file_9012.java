import java.math.BigInteger;
import java.util.Scanner;

public class Main {

    public static final BigInteger ZERO = BigInteger.ZERO;
    public static final BigInteger ONE = BigInteger.ONE;
    public static final BigInteger TWO = ONE.add(ONE);

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        int N = Integer.parseInt(sc.next());
        int M = Integer.parseInt(sc.next());
        int [] Ai = new int[N+1];

        for (int i = 0; i < M; i++) {

            Ai[Integer.parseInt(sc.next())] = -1;
        }

        sc.close();

        BigInteger ans = fanc(N,Ai);

        System.out.println(ans.remainder(BigInteger.valueOf(1000000007)));
    }

    public static BigInteger fanc(int N, int[] Ai) {

        BigInteger[] dp = new BigInteger[N+1];

        dp[0] = ONE;
        dp[1] = (Ai[1] == -1) ? ZERO : ONE;

        for (int i = 2; i <= N; i++ )  {

            dp[i-2] = (Ai[i-2] == -1) ? ZERO : dp[i-2];
            dp[i-1] = (Ai[i-1] == -1) ? ZERO : dp[i-1];

            dp[i] = dp[i-2].add(dp[i-1]);
        }

        return dp[N];
    }
}
