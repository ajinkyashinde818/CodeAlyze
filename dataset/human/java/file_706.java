import java.util.Scanner;

public class Main {
    private static final int MOD = 1_000_000_007;
    private static final String YES = "Yes";
    private static final String NO = "No";

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int N = sc.nextInt();
        int R = sc.nextInt();

        System.out.println(solve(N, R));
    }

    private static int solve(int N, int R) {
        if (N>=10) return R;

        return R + 100 * (10-N);
    }
}
