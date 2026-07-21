import java.math.*;
import java.util.*;

public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int K = sc.nextInt();
    int N = sc.nextInt();
    int[] A = new int[N];
    for (int i = 0; i < N; i++)
      A[i] = sc.nextInt();
    sc.close();

    int max = A[0] + K - A[N - 1];
    for (int i = 1; i < N; i++)
      max = Integer.max(max, A[i] - A[i - 1]);

    long ans = K - max;
    System.out.println(ans);
  }
}
