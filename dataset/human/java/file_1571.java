import java.util.*;
import java.math.*;

public class Main {

  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int n = sc.nextInt();
    int m = sc.nextInt();

    String[] a = new String[n];
    String b = "";

    for (int i = 0; i < n; i++) {
      a[i] = sc.next();
    }

    for (int i = 0; i < m; i++) {
      b += sc.next();
    }

    if (n == m) {
      if (a[0].equals(b)) {
        System.out.println("Yes");
        return;
      }
    }

    for (int i = 0; i < n-m; i++) {
      for (int j = 0; j < n-m; j++) {
        if (solve(i,j,a,b,m)) {
          System.out.println("Yes");
          return;
        }
      }
    }

    System.out.println("No");

  }

  public static boolean solve (int i, int j, String[] a, String b, int m) {
    String k = "";
    for (int l = 0; l < m; l++) {
      k += a[j+l].substring(i,i+m);
    }

    if (k.equals(b)) {
      return true;
    }

    return false;

  }

}
