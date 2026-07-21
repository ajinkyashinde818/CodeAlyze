import java.util.Arrays;
import java.util.Scanner;

public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int K = sc.nextInt();
    int N = sc.nextInt();
    int[] A = new int[N];
    for (int i = 0; i < N; i++) {
      A[i] = sc.nextInt();
    }
    Arrays.sort(A);
    int max = 0;
    for (int i = 1; i < N; i++) {
      max = Math.max(A[i] - A[i-1], max);
    }
    max = Math.max(K + A[0] - A[N-1], max);
    System.out.print(K - max);
  }
}
