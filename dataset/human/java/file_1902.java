import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        try (Scanner sc = new Scanner(System.in);) {
            new Main().solve(sc);
        }
    }

    void solve(Scanner sc) {
        int d = sc.nextInt();
        int g = sc.nextInt();
        int[] p = new int[d];
        int[] c = new int[d];
        for (int i = 0; i < d; i++) {
            p[i] = sc.nextInt();
            c[i] = sc.nextInt();
        }

        int ans = Integer.MAX_VALUE;
        for (int i = 0; i < (1 << d); i++) {
            int point = 0;
            int count = 0;
            for (int j = 0; j < d; j++) {
                if (((i >> j) & 1) == 1) {
                    point += c[j] + (j + 1) * 100 * p[j];
                    count += p[j];
                }
            }

            if (point < g) {
                count = plus(p, c, i, d, count, point, g);
            }
            ans = Math.min(ans, count);
        }
        System.out.println(ans);
    }

    int plus(int[] p, int[] c, int i, int d, int count, int point, int g) {
        for (int j = d - 1; j >= 0; j--) {
            if (((i >> j) & 1) == 0) {
                for (int k = 0; k < p[j]; k++) {
                    point += (j + 1) * 100;
                    count++;

                    if (point >= g) {
                        return count;
                    }
                }
            }
        }
        return count;
    }
}
