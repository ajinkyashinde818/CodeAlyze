import java.util.Scanner;

public class Main {
    private static final int MOD = 1_000_000_007;
    private static final String YES = "Yes";
    private static final String NO = "No";

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        long N = sc.nextLong();
        System.out.println(solve(N));
    }

    private static long solve(long N) {
        if (N%2 != 0) return 0;
        long ans = 0;

        for (long count=10; count<=N; count*=5) {
            ans += N/count;
        }

        return ans;
    }
}
