import java.util.*;

public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int n = sc.nextInt();
    long[] a = new long[n];
    int p = 0;
    int ki = 0;
    long s = 0;
    long mi = Long.MAX_VALUE;
    for(int i = 0; i < n; i++) {
      a[i] = sc.nextLong();
      if(a[i] == 0) p++;
      if(a[i] < 0) ki++;
      s += Math.abs(a[i]);
      mi = Math.min(mi, Math.abs(a[i]));
    }
    long ans = 0;
    if(p > 0) {
      ans = s;
    } else {
      if((ki % 2) == 0) {
        ans = s;
      } else {
        ans = s - 2 * mi;
      }
    }
    System.out.println(ans);
  }
}
