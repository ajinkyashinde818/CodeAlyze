import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int n = Integer.parseInt(scan.next());
        int m = Integer.parseInt(scan.next());
        int x = Integer.parseInt(scan.next());
        int[] c = new int[n];
        int[][] a = new int[n][m];
        for (int i = 0; i < n; i++) {
            c[i] = Integer.parseInt(scan.next());
            for (int j = 0; j < m; j++) {
                a[i][j] = Integer.parseInt(scan.next());
            }
        }
        scan.close();

        int ans = Integer.MAX_VALUE;
        for (int bit = 0; bit < (1 << n); bit++) {
            int[] rikaido = new int[m];
            int money = 0;
            for (int i = 0; i < n; i++) {
                if ((bit & (1 << i)) != 0) {
                    for (int j = 0; j < m; j++) {
                        rikaido[j] += a[i][j];
                    }
                    money += c[i];
                }
            }

            boolean isSatisfied = true;
            for (int j = 0; j < m; j++) {
                if (rikaido[j] < x) {
                    isSatisfied = false;
                    break;
                }
            }

            if (isSatisfied) {
                ans = Math.min(ans, money);
            }
        }

        if (ans == Integer.MAX_VALUE) {
            System.out.println(-1);
        } else {
            System.out.println(ans);
        }

    }
}
