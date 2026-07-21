import java.util.*;

public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int d = Integer.parseInt(sc.next());
    int g = Integer.parseInt(sc.next()) / 100;
    int sum;
    int[] p = new int[d];
    int[] c = new int[d];
    int ans = Integer.MAX_VALUE;
    for(int i = 0; i < d; i++) {
      p[i] = Integer.parseInt(sc.next());
      c[i] = Integer.parseInt(sc.next()) / 100;
    }
    int count;
    for(int i = 0; i < 1 << d; i++) {
      sum = 0;
      count = 0;
      int[] used = new int[d];
      for(int j = 0; j < d; j++) {
        if((1 & i >> j) == 1) {
          sum += p[j] * (j + 1) + c[j];
          count += p[j];
          used[j] = 1;
        }
      }
      for(int j = d - 1; j >= 0; j--) {
        if(sum >= g) break;
        if(used[j] == 0) {
          for(int k = 0; k < p[j] - 1; k++) {
            sum += j + 1;
            count++;
            if(sum >= g) break;
          }
        }
      }
      if(sum >= g) ans = Math.min(ans, count);
    }
    System.out.println(ans);
  }
}
