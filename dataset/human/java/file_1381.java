import java.util.*;

public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int N = sc.nextInt();
    int M = sc.nextInt();
    char[][] A = new char[N][N];
    char[][] B = new char[M][M];
    for (int i = 0; i < N; i++) {
      A[i] = sc.next().toCharArray();
    }
    for (int i = 0; i < M; i++) {
      B[i] = sc.next().toCharArray();
    }
    int count = 0;
    for (int i = 0; i < N - M + 1; i++) {
      for (int j = 0; j < N - M + 1; j++) {
        boolean contain = true;
        for (int k = 0; k < M; k++) {
          for (int l = 0; l < M; l++) {
            if (A[i + k][j + l] != B[k][l]) {
              contain = false;
            }
          }
        }
        if (contain) {
          count++;
        }
      }
    }
    if (count > 0) {
      System.out.println("Yes");
    } else {
      System.out.println("No");
    }
  }
}
