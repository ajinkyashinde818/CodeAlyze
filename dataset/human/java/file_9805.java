import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        @SuppressWarnings("resource")
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        int x = sc.nextInt();
        int[] c = new int[n];
        int[][] a = new int[n][m];
        for (int i = 0 ; i < n ; i++) {
            c[i] = sc.nextInt();
            for (int j = 0 ; j < m ; j++) {
                a[i][j] = sc.nextInt();
            }
        }

        int min = 100000000;
        for (int i = 0 ; i < Math.pow(2, n) ; i++) {
            int[] b = new int[n];
            int temp = i;
            for (int j = 0 ; j < n ; j++) {
                b[j] = temp % 2;
                temp /= 2;
            }
            int[] p = new int[m];
            int sum = 0;
            for (int j = 0 ; j < n ; j++) {
                if (b[j] == 1) sum += c[j];
                for (int k = 0 ; k < m ; k++) {
                    if (b[j] == 1) {
                        p[k] += a[j][k];
                    }
                }
            }
            boolean flg = true;
            for (int j = 0 ; j < m ; j++) {
                if (p[j] < x) flg = false;
            }
            if (flg) min = Math.min(min, sum);
        }
        System.out.println(min == 100000000 ? -1 : min);
    }

}
