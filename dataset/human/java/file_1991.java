import java.util.*;

public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    long n = sc.nextLong();
    HashMap<Long, Integer> map = new HashMap<Long, Integer>();
    long m = n;
    for(long i = 2; (i * i) <= n; i++) {
      int t = 0;
      while((m % i) == 0) {
        t++;
        m /= i;
      }
      if(t > 0) map.put(i, t);
    }
    if(m > 1) map.put(m, 1);
    long ans = 0;
    for(long key : map.keySet()) {
      int c = map.get(key);
      int p = 1;
      while(c > 0) {
        ans++;
        if((c - p) > p) {
          c -= p;
          p++;
        } else {
          c = 0;
        }
      }
    }
    System.out.println(ans);
  }
}
