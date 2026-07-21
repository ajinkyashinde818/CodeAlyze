import java.util.Scanner;

public class Main {
  private static void solve(int n, int[] a, int[] b, int[] c) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
      sum += b[a[i] - 1];
      if (i > 0 && a[i] == a[i - 1] + 1) sum += c[a[i - 1] - 1];
    }
    System.out.println(sum);
  }
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int n = Integer.parseInt(sc.nextLine());
    String[] as = sc.nextLine().split(" ");
    int[] a = new int[n];
    for (int i = 0; i < n; i++) a[i] = Integer.parseInt(as[i]);
    String[] bs = sc.nextLine().split(" ");
    int[] b = new int[n];
    for (int i = 0; i < n; i++) b[i] = Integer.parseInt(bs[i]);
    String[] cs = sc.nextLine().split(" ");
    int[] c = new int[n - 1];
    for (int i = 0; i < n - 1; i++) c[i] = Integer.parseInt(cs[i]);
    sc.close();
    solve(n, a, b, c);
  }
}
