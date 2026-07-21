import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int D = sc.nextInt();
        int G = sc.nextInt();
        int[] p = new int[D];
        int[] c = new int[D];
        int total = 0;
        for (int i = 0; i < D; i++) {
            p[i] = sc.nextInt();
            c[i] = sc.nextInt();
            total += p[i];
        }
        int[] dp = new int[total + 1];
        for (int i = 0; i < D; i++)
            for (int k = dp.length - 1; k >= 0; k--)
                if (k == 0 || dp[k] > 0 && dp[k] < G)
                    for (int j = 1; j <= p[i]; j++) {
                        int point = j * 100 * (i + 1);
                        if (j == p[i]) point += c[i];
                        if (dp[k] + point > dp[k + j])
                            dp[k + j] = dp[k] + point;
                    }
        for (int i = 1; i < dp.length; i++)
            if (dp[i] >= G) {
                System.out.println(i);
                break;
            }

        sc.close();
    }
}
