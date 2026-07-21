import java.util.Scanner;

public class Main {
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);

    int N = scanner.nextInt();
    int M = scanner.nextInt();
    char[][] A = new char[N][N];
    char[][] B = new char[M][M];
    for (int i = 0; i < N; i++) A[i] = scanner.next().toCharArray();
    for (int i = 0; i < M; i++) B[i] = scanner.next().toCharArray();
    for (int x = 0; x <= N - M; x++) {
      for (int y = 0; y <= N - M; y++) {
        boolean match = true;
        for (int i = 0; i < M; i++) {
          for (int j = 0; j < M; j++) {
            match &= A[x + i][y + j] == B[i][j];
          }
        }
        if (match) {
          System.out.println("Yes");
          return;
        }
      }
    }
    System.out.println("No");
  }
}
