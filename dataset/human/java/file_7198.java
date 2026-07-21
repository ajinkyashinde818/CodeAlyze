import java.util.*;
import java.math.*;

public class Main {

  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    long k = sc.nextLong();
    int n = sc.nextInt();

    long[] a = new long[n];

    for (int i = 0; i < n; i++) {
      a[i] = sc.nextLong();
    }

    long sum = 0;

    long[] data = new long[n+1];
    data[n] = k-a[n-1];
    data[0] = a[0];

    for (int i = 1; i < n; i++) {
      data[i] = a[i]-a[i-1];
    }

    // for (int i = 0; i <= n; i++) {
    //   System.out.println(data[i]);
    // }

    Arrays.sort(data);

    for (int i = 0; i < n; i++) {
      sum += data[i];
    }

    long ans = 0;

    for (int i = n-1; i > 0; i--) {
      ans += a[i]-a[i-1];
    }

    System.out.println(Math.min(ans,sum));

  }

}
