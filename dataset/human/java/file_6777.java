import java.util.Arrays;
import java.util.Scanner;

public class Main {
  public static void main(String[] args) {
    final Scanner scanner = new Scanner(System.in);
    final int k = scanner.nextInt();
    scanner.nextLine();
    final int[] a = Arrays.stream(scanner.nextLine().split(" ")).mapToInt(Integer::parseInt).toArray();

    final int[] extended = new int[a.length * 2];
    for (int i = 0; i < a.length * 2; i++) {
      extended[i] = a[i % a.length];
      if (i >= a.length) extended[i] += k;
    }

    int min = Integer.MAX_VALUE;
    for (int i = 0; i < a.length; i++) {
      min = Math.min(min, extended[i + a.length - 1] - extended[i]);
    }
    System.out.println(min);
  }
}
