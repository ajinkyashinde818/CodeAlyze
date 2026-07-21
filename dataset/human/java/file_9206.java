import java.util.Scanner;

public class Main {
    public static int from = 0;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int steps = sc.nextInt();
        long[] dp = new long[steps + 1];

        int breaks = sc.nextInt();
        int[] br = new int[breaks];
        for (int i = 0; i < breaks; i++) {
            br[i] = sc.nextInt();
        }


        dp[0] = 1;
        if (isBroken(br, 1, from) ) {
            dp[1] = 0;
            from = 1;
        } else {
            dp[1] = 1;
        }

        int mod = 1000000007;
        for (int step = 2; step <= steps; step++) {
            dp[step] = 0;
            if (!isBroken(br, step, from)) {
                dp[step] = (dp[step - 1] + dp[step - 2]) % mod;
            }
        }

        System.out.println(dp[steps]);
    }

    public static boolean isBroken(int[] broken, int step, int from) {
        for (int i = from; i < broken.length; i++) {
            if (broken[i] == step) {
                Main.from = i;
                return true;
            }
        }
        return false;
    }
}
