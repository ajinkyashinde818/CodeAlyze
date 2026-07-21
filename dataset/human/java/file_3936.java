import java.util.Scanner;

public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);

    int n = sc.nextInt();

    int[] a = new int[n];
    for (int i = 0; i < n; i++) {
      a[i] = sc.nextInt();
    }

    int[] b = new int[n];
    for (int i = 0; i < n; i++) {
      b[i] = sc.nextInt();
    }

    int[] c = new int[n - 1];
    for (int i = 0; i < n - 1; i++) {
      c[i] = sc.nextInt();
    }

    int before = -99;
    int satisfaction = 0;
    for (int i = 0; i < n; i++) {

      satisfaction += b[a[i] - 1];
      if (before + 1 == a[i]) {
        satisfaction += c[before - 1];
      }
      before = a[i];
    }
    System.out.println(satisfaction);
  }
}
