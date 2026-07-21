import java.util.*;
import java.math.*;

public class Main {

  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);

    int n = sc.nextInt();
    int m = sc.nextInt();
    int x = sc.nextInt();
    int[] c = new int[n];
    int[][] a = new int[n][m];

    for (int i = 0; i < n; i++) {
      c[i] = sc.nextInt();
      for (int j = 0; j < m; j++) {
        a[i][j] = sc.nextInt();
      }
    }

    long ans = Long.MAX_VALUE;

    for (int i = 0; i < Math.pow(2,n); i++) {
      boolean ok = true;
      long res = 0;
      for (int k = 0; k < m; k++) {
        long sum = 0;
        for (int j = 0; j < n; j++) {
          if ((1&i >> j) == 1) {
            res += c[j];
            sum += a[j][k];
          }
          // System.out.println(sum);
        }
        if (sum < x) {
          ok = false;
        }
        // System.out.println();
      }
      // System.out.println(res/m);
      if (ok) {
        ans = Math.min(ans,res/m);
      }
    }

    if (ans == Long.MAX_VALUE) {
      System.out.println(-1);
    } else {
      System.out.println(ans);
    }

  }

}
