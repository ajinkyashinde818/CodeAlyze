import java.util.*;
public class Main {

  public static void main(String[] args) { 
      Scanner sc = new Scanner(System.in);
      int n = sc.nextInt();
      int m = sc.nextInt();
      int x = sc.nextInt();
      int[][] arr = new int[n][m + 1];
      for(int i = 0; i < n; i++)
        for(int j = 0; j <= m; j++)
          arr[i][j] = sc.nextInt();

      long res = Long.MAX_VALUE;
      for(int i = 0; i < (2 << n); i++) {
        int[] sum = new int[m+1];
        int cost = 0;
        for(int j = n - 1; j >= 0; j--) {
            if( (1 & i >> j) == 1) {
                cost += arr[j][0];
                for(int k = 1; k <= m; k++)
                  sum[k] += arr[j][k];
            }
        }
        boolean flag = true;
        for(int k = 1; k <= m; k++)
          if(sum[k] < x) {
            flag = false;
            break;
          }
        if(flag) res = Math.min(res, cost);
      }
      System.out.println(res == Long.MAX_VALUE ? -1: res);
  }
}
