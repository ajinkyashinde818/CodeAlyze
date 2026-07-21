import java.util.*;
import java.math.*;

public class Main {

  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int d = sc.nextInt();
    int g = sc.nextInt();
    long[] p = new long[d];
    long[] c = new long[d];

    for (int i = 0; i < d; i++) {
      p[i] = sc.nextLong();
      c[i] = sc.nextLong();
    }

    long ans = Long.MAX_VALUE;

    for (int i = 0; i < Math.pow(2,d); i++) {
      long sum = 0;
      long count = 0;
      for (int j = 0; j < d; j++) {
        if ((1&i >> j) == 1) {
          sum += p[j]*100*(j+1)+c[j];
          count += p[j];
          // System.out.println(count);
        }
      }

      // sum >= gかどうかで場合分け

      if (sum >= g) {
        ans = Math.min(ans,count);
      } else {
        for (int j = d-1; j >= 0; j--) {
          if ((1&i >> j) != 1) {
            for (int k = 0; k < p[j]; k++) {
              sum += 100*(j+1);
              count++;
              // System.out.println(sum+"   "+count);
              if (sum >= g) {
                // System.out.println(sum);
                ans = Math.min(ans,count);
              }
            }
          }
        }
      }
    }

    System.out.println(ans);

  }

}
