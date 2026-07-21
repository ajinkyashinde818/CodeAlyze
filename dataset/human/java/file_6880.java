import java.util.Scanner;

public class Main {
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);

    int K = scanner.nextInt();
    int N = scanner.nextInt();
    int[] A = new int[N];
    for (int i = 0; i < N; i++) A[i] = scanner.nextInt();

    int max = A[0] + K - A[N - 1];
    for (int i = 1; i < N; i++) {
      max = Math.max(max, A[i] - A[i - 1]);
    }
    System.out.println(K - max);
  }
}
