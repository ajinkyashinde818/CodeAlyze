import java.math.BigInteger;
import java.util.*;
import java.util.stream.Collectors;

public class Main {
  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
    long n = sc.nextLong();
    if (n == 1) {
      System.out.println(0);
      return;
    }
    TreeSet<Long> set = getSet();

    long result = 0;
    for (long i = 2; i * i <= n; i++) {
      if (n % i == 0) {
        int count = 0;
        while (n % i == 0) {
          n /= i;
          count++;
        }
        result += set.headSet((long) count, true).size();
      }
    }
    System.out.println(n > 1 ? result + 1 : result);
  }

  static TreeSet<Long> getSet() {
    TreeSet<Long> r = new TreeSet<>();
    long sum = 0;
    for (int i = 1; sum < 40; i++) {
      sum += i;
      r.add(sum);
    }
    return r;
  }
}
