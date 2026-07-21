import java.util.Arrays;
import java.util.Scanner;


class Main {
    static Scanner sc = new Scanner(System.in);

    static long[] x = new long[100005];
    static long[] v = new long[100005];
    static long[] s = new long[100005];
    static long n, c;
    static long ans = 0;
    static long sum;
    
    public static void main(String[] args) {
        Arrays.fill(x, 0);
        Arrays.fill(v, 0);
        Arrays.fill(s, 0);
        
        n = sc.nextLong();
        c = sc.nextLong();

        for (int i = 1; i <= n; i++) {
            x[i] = sc.nextLong();
            v[i] = sc.nextLong();
        }
        x[(int)n + 1] = c;

        // origin -> right -> origin -> left
        Arrays.fill(s, Long.MIN_VALUE);

        sum = 0;
        s[0] = 0;
        for (int i = 1; i <= n; i++) {
            sum += v[i];

            s[i] = Math.max(sum - x[i] * 2, s[i - 1]);
        }

        sum = 0;
        for (int i = (int)n + 1; i > 0; i--) {
            sum += v[i];
            ans = Math.max(ans, s[i - 1] + sum - (c - x[i]));
        }

        // origin -> left -> origin -> right
        Arrays.fill(s, Long.MIN_VALUE);

        sum = 0;
        s[0] = 0;
        for (int i = 1; i <= n; i++) {
            sum += v[i];
            s[i] = Math.max(sum - x[i], s[i - 1]);
        }

        sum = 0;
        for (int i = (int)n + 1; i > 0; i--) {
            sum += v[i];
            ans = Math.max(ans, s[i - 1] + sum - (2 * c - 2 * x[i]));
        }

        System.out.println(ans);
    }
}
