import java.util.*;

public class Main {
  public static void main(String[] args) {
    Scanner s = new Scanner(System.in);
    int n = s.nextInt();
    long[] a = new long[n];
    
    for (int i = 0; i < n; i++) {
      a[i] = s.nextLong();
    }
    
    long dpMaxCurrentPositive = 0;
    long dpMaxCurrentNegative = -(1L << 40);
    
    for (int i = 1; i < n; i++) {
      long nextDpMaxCurrentPositive = Math.max(dpMaxCurrentPositive + a[i-1], dpMaxCurrentNegative - a[i-1]);
      long nextDpMaxCurrentNegative = Math.max(dpMaxCurrentPositive - a[i-1], dpMaxCurrentNegative + a[i-1]);
      dpMaxCurrentPositive = nextDpMaxCurrentPositive;
      dpMaxCurrentNegative = nextDpMaxCurrentNegative;
    }
    long maxValue = Math.max(dpMaxCurrentPositive + a[n-1], dpMaxCurrentNegative - a[n-1]);
    System.out.println(maxValue);
  }
}
