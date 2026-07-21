import java.util.*;

public class Main {
    private static final int INF = 114514;

    public void main(Scanner sc) {
        int d = sc.nextInt();
        int g = sc.nextInt() / 100;
        int p[] = new int[d];
        int c[] = new int[d];
        int pef[] = new int[d];
        for (int i = 0; i < d; i++) {
            p[i] = sc.nextInt();
            c[i] = sc.nextInt() / 100;
            pef[i] = p[i] * (i + 1) + c[i];
        }
        sc.close();

        int ans[][] = new int[d][105501];
        for (int i = 0; i < d; i++) {
            Arrays.fill(ans[i], INF);
        }

        for (int i = 0; i < d; i++) {
            ans[i][0] = 0;
        }
        for (int i = 1; i < p[0]; i++) {
            ans[0][i] = i;
        }
        ans[0][pef[0]] = p[0];

        for (int i = 2; i <= d; i++) {
            for (int j = 0; j < p[i - 1]; j++) {
                for (int k = 0; k <= 105500; k++) {
                    if (ans[i - 2][k] != INF) {
                        ans[i - 1][k + j * i] = Math.min(ans[i - 2][k + j * i], ans[i - 2][k] + j);
                    }
                }
            }
            for (int k = 0; k <= 105500; k++) {
                if (ans[i - 2][k] != INF) {
                    ans[i - 1][k + pef[i - 1]] = Math.min(ans[i - 2][k + pef[i - 1]], ans[i - 2][k]
                            + p[i - 1]);
                }
            }
        }

        int min = INF;
        for (int i = g; i <= 105500; i++) {
            min = Math.min(min, ans[d - 1][i]);
        }
        System.out.println(min);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        new Main().main(sc);
    }
}
