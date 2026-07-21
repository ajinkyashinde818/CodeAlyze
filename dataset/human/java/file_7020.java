import java.util.*;

public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int k = sc.nextInt();
    int n = sc.nextInt();
    int ans = k;
    int[] a = new int[n];
    for(int i = 0; i < n; i++) {
      a[i] = sc.nextInt();
    }
    ans = a[n - 1] - a[0];
    for(int i = 1; i < n; i++) {
      ans = Math.min(ans, k - (a[i] - a[i - 1]));
    }
    System.out.println(ans);
  }
}
