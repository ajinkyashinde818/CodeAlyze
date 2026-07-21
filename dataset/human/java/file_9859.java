import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        int x = sc.nextInt();
        int[] c = new int[n];
        int[][] a = new int[n][m];
        int[] sum = new int[m];
        int min = 0;
        for (int i = 0; i < n; i++) {
            c[i] = sc.nextInt();
            min += c[i];
            for (int j = 0; j < m; j++) {
                a[i][j] = sc.nextInt();
                sum[j] += a[i][j];
            }
        }

        // NG case
        if (!check(sum, m, x)) {
            System.out.println(-1);
            return;
        }

        for (int i = 0; i < Math.pow(2, n); i++) {
            int[] score = new int[m];
            int cost = 0;
            for (int j = 0; j < n; j++) {
                if ((1&i>>j) == 1) {
                    for (int k = 0; k < m; k++) {
                        score[k] += a[j][k];
                    }
                    cost += c[j];
                }
            }

            //System.out.println("i="+i);
            //System.out.println("cost="+cost);


            if (check(score, m, x) && min > cost) {
                min = cost;
            }
        }

        System.out.println(min);
    }

    public  static boolean check(int[] score, int m, int x) {
        for (int i = 0; i < m; i++) {
            if (score[i] < x) {
                return false;
            }
        }

        return true;
    }
}
