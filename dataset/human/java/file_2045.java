import java.util.*;
public class Main {

  public static void main(String[] args) { 
      Scanner sc = new Scanner(System.in);
      long n = sc.nextLong();
      List<long[]> factors = new ArrayList<>();
      for(long i = 2; i * i <= n; i++) {
        long cnt = 0;
        while(n % i == 0) {
          cnt++;
          n /= i;
        }
        if(cnt != 0)
          factors.add(new long[]{i, cnt});
      }
      if(n != 1)
        factors.add(new long[]{n, 1});

      long res = 0;
      for(long[] ts : factors) {
        long t = ts[1];
        long i = 1; 
        while(t >= i) {
          res++;
          t -= i;
          i++;
        }
      }
      System.out.println(res);
  }
}
