import java.util.Arrays;
import java.util.Scanner;

public class Main {

  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);
    int k = scanner.nextInt();
    int n = scanner.nextInt();
    int[] a = new int[n];
    int max = 0;

    for (int i = 0; i < n; i++) {
      a[i] = scanner.nextInt();
    }
    Arrays.sort(a);

    for (int i = 0; i < n; i++) {
      max = Math.max(max,
          Math.min(Math.abs(a[(i + 1) % n] - a[i % n]), k - Math.abs(a[(i + 1) % n] - a[i % n])));
    }
    System.out.println(k - max);
  }

}
