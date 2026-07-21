import java.util.*;

public class Main {

    /**
     * @param args
     */
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int N = sc.nextInt();
        int K = sc.nextInt();
        int S = sc.nextInt();

        int[] ans = solve(N, K, S);

        for (int i=0; i<ans.length; i++) {
            System.out.println(ans[i]);
        }
    }

    private static int[] solve(int N, int K, int S) {
        int[] a = new int[N];

        int b;
        if (S == 1_000_000_000) {
            b = 1;
        } else {
            b = 1_000_000_000;
        }

        for (int i=0; i<N; i++) {
            if (i < K) {
                a[i] = S;
            } else {
                a[i] = b;
            }
        }

        return a;
    }
}
