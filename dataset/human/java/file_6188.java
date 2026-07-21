import java.util.*;

public class Main {
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);
    try {
      long k = scanner.nextLong();
      long s = scanner.nextLong();
      long ans = 0;
      for (long x = 0; x <= k; x++) {
        for (long y = 0; y <= k; y++) {
          long z = s - x - y;
          if (0 <= z && z <= k) ans++;
        }
      }
      
      System.out.println(ans);
    } finally {
      scanner.close();
    }
  }
}
