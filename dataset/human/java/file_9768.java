import java.util.*;

public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int N = sc.nextInt();
    int M = sc.nextInt();
    int X = sc.nextInt();
    int[] C = new int[N];
    int[][] A = new int[N][M];
    for (int i = 0; i < N; i++) {
      C[i] = sc.nextInt();
      for (int j = 0; j < M; j++) {
        A[i][j] = sc.nextInt();
      }
    }
    sc.close();

    long ans = -1;
    long max = 1 << 12;
    for (long n = 1; n < max; n++ ) {
      long sumC = 0;
      long[] sumA = new long[M];
      for (int i = 0; i < N; i++)
        if ((n >>> i) % 2 == 1) {
          sumC += C[i];
          for (int j = 0; j < M; j++)
            sumA[j] += A[i][j];
        }

      boolean ok = true;
      for (int j = 0; j < M; j++)
        if (sumA[j] < X) ok = false;

      if (ok && (ans < 0 || sumC < ans))
        ans = sumC;
    }

    System.out.println(ans);
  }
}
