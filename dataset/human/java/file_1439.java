import java.util.*;

public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int N = sc.nextInt();
    int M = sc.nextInt();

    char[][] A = new char[N][N];
    for (int i = 0; i < N; i++) {
      String s = sc.next();
      for (int j = 0; j < N; j++) {
        A[i][j] = s.charAt(j);
      }
    }
    
    char[][] B = new char[M][M];
    for (int i = 0; i < M; i++) {
      String s = sc.next();
      for (int j = 0; j < M; j++) {
        B[i][j] = s.charAt(j);
      }
    }
    
    boolean ans = false;
    for (int i = 0; i <= N-M; i++) {
      for (int j = 0; j <= N-M; j++) {
        if (match(A, B, i, j)) {
          ans = true;
          break;
        }
      }
    }
    
    System.out.println(ans ? "Yes" : "No");
  }
  
  private static boolean match(char[][] A, char[][] B, int i, int j) {
    for (int m = 0; m < B.length; m++) {
      for (int n = 0; n < B[m].length; n++) {
        if (A[i+m][j+n] != B[m][n]) {
          return false;
        }
      }
    }
    return true;
  }
}
