import java.util.*;
public class Main
{
    public static void main(String [] args)
    {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt(); int m = sc.nextInt(); int x = sc.nextInt();
        int [] c = new int [n]; int [][] p = new int [n][m];
        for (int i = 0; i < n; i++) {
            c[i] = sc.nextInt();
            for (int j = 0; j < m; j++) p[i][j] = sc.nextInt();
        }
        int ans = Integer.MAX_VALUE;
        for (int i = 0; i <= ((1 << n) - 1); i++) {
            int [] arr = new int [m]; int cost = 0;
            for (int j = 0; j <= n - 1; j++) {
                if (((i & (1 << j)) >>> j) == 1) {
                    for (int k = 0; k < m; k++) {
                        arr[k] += p[j][k];
                    }
                    cost += c[j];
                }
            }
            boolean good = true;
            for (int j = 0; j < m; j++) {
                if (arr[j] < x) good = false;
            }
            if (good) ans = Math.min(ans, cost);
        }
        System.out.println(ans == Integer.MAX_VALUE ? -1 : ans);
    }


}
