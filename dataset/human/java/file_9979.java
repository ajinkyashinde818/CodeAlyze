import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = Integer.parseInt(sc.next());
        int m = Integer.parseInt(sc.next());
        int x = Integer.parseInt(sc.next());

        int[] c = new int[n];
        int[][] a = new int[n][m];

        for (int i = 0; i < n; i++) {
            c[i] = sc.nextInt();
            for (int j = 0; j < m; j++) {
                a[i][j] = sc.nextInt();
            }
        }

        int ans = Integer.MAX_VALUE;
        boolean flag = false;
        loop: for (int i = 0; i < (1 << n); i++) {
            int[] s = new int[m];
            int tmp = 0;
            for (int j = 0; j < n; j++) {
                if ((1 & i >> j) == 1) {
                    tmp += c[j];
                    for (int k = 0; k < m; k++) {
                        s[k] += a[j][k];
                    }
                }
            }

            for (int j = 0; j < m; j++) {
                if (s[j] < x) {
                    continue loop;
                }
            }
            ans = Math.min(ans, tmp);
            flag = true;
        }

        System.out.println(flag ? ans : -1);
        sc.close();
    }

}
