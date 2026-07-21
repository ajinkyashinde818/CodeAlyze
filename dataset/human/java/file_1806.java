import java.util.*;

public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int d = sc.nextInt();
    int g = sc.nextInt();
    int[] p = new int[d];
    int[] c = new int[d];
    for(int i = 0; i < d; i++) {
      p[i] = sc.nextInt();
      c[i] = sc.nextInt();
    }
    int ans = Integer.MAX_VALUE;
    if((100 * d * (p[d - 1] - 1)) >= g) {
      if((g % (100 * d)) == 0) {
        ans = Math.min(ans, g / (100 * d));
      } else {
        ans = Math.min(ans, (g / (100 * d)) + 1);
      }
    }
    for(int i = 1; i < Math.pow(2, d); i++) {
      int sum = 0;
      int s = 0;
      int q = 0;
      for(int j = 0; j < d; j++) {
        if((i & (1 << j)) != 0) {
          s += p[j];
          sum += ((100 * (j + 1) * p[j]) + c[j]);
        } else {
          q = j;
        }
      }
      if(sum >= g) ans = Math.min(ans, s);
      if((sum + (100 * (q + 1) * (p[q] - 1))) >= g) {
        if(g > sum) {
          int r = g - sum;
          if((r % (100 * (q + 1))) == 0) {
            s += (r / (100 * (q + 1)));
          } else {
            s += (r / (100 * (q + 1)) + 1);
          }
          ans = Math.min(ans, s);
        }
      }
    }
    System.out.println(ans);
  }
}
