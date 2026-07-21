import java.util.*;

public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int n = sc.nextInt();
    int m = sc.nextInt();
    int x = sc.nextInt();
    int[] c = new int[n];
    int[][] a = new int[n][m];
    for(int i = 0; i < n; i++) {
      c[i] = sc.nextInt();
      for(int j = 0; j < m; j++) {
        a[i][j] = sc.nextInt();
      }
    }
    int ans = (int)Math.pow(10, 7);
    for(int i = 1; i < (int)Math.pow(2, n); i++) {
      int t = 0;
      int[] tt = new int[m];
      for(int j = 0; j < n; j++) {
        if((i & (1 << j)) != 0) {
          t += c[j];
          for(int k = 0; k < m; k++) {
            tt[k] += a[j][k];
          }
        }
      }
      int q = 0;
      for(int j = 0; j < m; j++) {
        if(tt[j] >= x) q++;
      }
      if(q == m) ans = Math.min(ans, t);
    }
    if(ans == (int)Math.pow(10, 7)) ans = -1;
    System.out.println(ans);
  }
}
