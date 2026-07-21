import java.util.Arrays;
import java.util.Scanner;

public class Main {
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);

    int N = scanner.nextInt();
    int[] A = new int[N];
    int numMinus = 0;
    for (int i = 0; i < N; i++) {
      int a = scanner.nextInt();
      if (a < 0) numMinus--;
      A[i] = Math.abs(a);
    }
    Arrays.sort(A);
    long sum = 0;
    if (numMinus % 2 == 0) {
      sum += A[0];
    } else {
      sum -= A[0];
    }
    for (int i = 1; i < N; i++) sum += A[i];
    System.out.println(sum);
  }
}
