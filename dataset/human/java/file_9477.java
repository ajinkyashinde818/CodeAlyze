import java.util.Scanner;

public class Main {
  static Scanner in = new Scanner(System.in);
  static int[] a;
  static int[] b;
  static int n;
  public static void main(String[] args) {
    n = in.nextInt();
    a = new int[n];
    b = new int[n];
    for (int i = 0; i < n; i++) {
      a[i] = in.nextInt();
      b[i] = in.nextInt();
    }
    System.out.println(check());
  }
  static String check() {
    for (int i = 0; i + 2 < n; i++) {
      if (a[i] != b[i]) {
        continue;
      }
      if (a[i + 1] != b[i + 1]) {
        continue;
      }
      if (a[i + 2] != b[i + 2]) {
        continue;
      }
      return "Yes";
    }
    return  "No";
  }
}
