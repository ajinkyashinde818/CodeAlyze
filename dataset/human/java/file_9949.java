import java.util.*;

public class Main {
  public static void main(String... args) {
    Scanner input = new Scanner(System.in);
    
    int n = input.nextInt();
    int m = input.nextInt();
    int x = input.nextInt();
    int[] cost = new int[n];
    int[][] c = new int[n][m];
    for (int i = 0; i < n; i++) {
      cost[i] = input.nextInt();
      for (int j = 0; j < m; j++) {
        c[i][j] = input.nextInt();
      }
    }
    
    int ans = Integer.MAX_VALUE;
    for (int i = 0; i < (1 << n); i++) {
      int local = 0;
      int[] algo = new int[m];
      for (int j = 0; j < n; j++) {
        if ((i & (1 << j)) != 0) {
          local += cost[j];
          for (int k = 0; k < m; k++) {
            algo[k] += c[j][k];
          }
        }
      }
      
      boolean good = true;
      for (int j = 0; j < m && good; j++) {
        good &= (algo[j] >= x);
      }
      
      if (good) {
        ans = Math.min(ans, local);
      }
    }
    
    
    System.out.println(ans == Integer.MAX_VALUE ? -1 : ans);
  }
}
