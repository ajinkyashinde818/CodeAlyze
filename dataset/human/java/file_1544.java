import java.util.Scanner;

public class Main {
  
  public static void main(String[] args) {
    
    Scanner sc = new Scanner(System.in);
    
    int N = Integer.parseInt(sc.next());
    int M = Integer.parseInt(sc.next());
    
    byte A[][] = new byte[N][N];
    byte B[][] = new byte[M][M];
    
    String input;
    for (int i = 0; i < N; i++) {
      input = sc.next();
      for (int j = 0; j < N; j++) {
        if (input.charAt(j) == '#') {
          A[i][j] = 1;
        } else {
          A[i][j] = 0;
        }
      }
    }
    for (int i = 0; i < M; i++) {
      input = sc.next();
      for (int j = 0; j < M; j++) {
        if (input.charAt(j) == '#') {
          B[i][j] = 1;
        } else {
          B[i][j] = 0;
        }
      }
    }
    boolean flag = true;
    for (int i = 0; i <= N - M; i++) {
      for (int j = 0; j <= N - M; j++) {
        if (B[0][0] == A[i][j]) {
          flag = true;
          for (int k = 0; k < M; k++) {
            for (int l = 0; l < M; l++) {
              if (B[k][l] != A[i + k][j + l]) {
                flag = false;
                break;
              }
            }
            if (!flag) {
              break;
            }
          }
          if (flag) {
            System.out.println("Yes");
            return;
          }
        }
      }
    }
    
    System.out.println("No");
  }
}
