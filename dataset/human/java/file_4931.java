import java.util.*;

public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    long n = sc.nextLong();
    long ans = 0;
    if((n > 0) && ((n % 2) == 0)) {
      long t = n / 2;
      for(int i = 1; i < 50; i++) {
        long t1 = (long)Math.pow(5, i);
        ans += (t / t1);
      }
    }
    System.out.println(ans);
  }
}
