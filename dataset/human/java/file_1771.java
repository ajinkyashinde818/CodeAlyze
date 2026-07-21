import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        d = in.nextInt();
        g = in.nextInt();
        p = new int[d];
        c = new int[d];
        for (int i = 0; i < d; i++) {
            p[i] = in.nextInt();
            c[i] = in.nextInt();
        }
        visited = new boolean[d];

        System.out.println(backtrack(0));

    }

    static int[] p;
    static int[] c;
    static boolean[] visited;
    static int d;
    static int g;

    private static int backtrack(int sum) {
        if (sum >= g) {
            return 0;
        }
        int best = Integer.MAX_VALUE / 2;
        for (int j = 0; j < d; j++) {
            if (!visited[j]) {
                visited[j] = true;
                best = Math.min(best, Math.max(1, Math.min((g - sum) / ((j + 1) * 100), p[j])) + backtrack(sum + (j + 1) * 100 * p[j] + c[j]));
                visited[j] = false;
            }
        }
        return best;
    }
}
