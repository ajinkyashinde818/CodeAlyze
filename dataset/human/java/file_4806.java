import java.util.*;

public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    long N = sc.nextLong();
    sc.close();

    long ans = 0;
    if (N % 2 == 0)
      for (long n = 10; n <= N; n *= 5)
        ans += N / n;
    System.out.println(ans);
  }
}
