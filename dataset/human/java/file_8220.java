import java.util.Scanner;
import java.util.TreeMap;

public class Main {
  public static TreeMap<Long, Long> findPrimeFactors(long n) {
    TreeMap<Long, Long> res = new TreeMap<>();
    long m = n;
    for (long i = 2; i * i <= m; i++) {
      while (m % i == 0) {
        long val = 1 + res.getOrDefault(i, 0L);
        res.put(i, val);
        m /= i;
      }
    }
    if (m != 1) {
      long val = 1 + res.getOrDefault(m, 0L);
      res.put(m, val);
    }
    return res;
  }

  public static void main(String[] args) {
    Scanner input = new Scanner(System.in);
    String[] ss = input.nextLine().split(" ");
    long a = Long.parseLong(ss[0]);
    long b = Long.parseLong(ss[1]);
    TreeMap<Long, Long> fa = findPrimeFactors(a);
    TreeMap<Long, Long> fb = findPrimeFactors(b);
    for (long p: fb.keySet()) {
      long val = fa.getOrDefault(p, 0L);
      fa.put(p, Long.max(fb.get(p), val));
    }
    long ans = 1;
    for (long p: fa.keySet()) {
      long temp = 1;
      for (int i = 0; i < fa.get(p); i++) {
        temp *= p;
      }
      ans *= temp;
    }
    System.out.println(ans);
  }
}
