import java.util.Scanner;

public class Main {

  public static void main(String[] args) {

    Scanner sc = new Scanner(System.in);

    int n = Integer.parseInt(sc.next());

    int[] a = new int[n];
    long sum = 0l;
    for (int i = 0; i < n; i++) {
      a[i] = Integer.parseInt(sc.next());
      sum += a[i];
    }

    long x = a[0];
    long y = sum - a[0];
    long ans = Math.abs(x - y);

    for (int i = 1; i < n - 1; i++) {
      x += a[i];
      y -= a[i];
      ans = Math.min(ans, Math.abs(x - y));
      // System.out.println(ans);
    }

    System.out.println(ans);
    sc.close();
  }

}
