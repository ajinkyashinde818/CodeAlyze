import java.util.*;

public class Main {

  public static void main (String[] args) {
    Scanner sc = new Scanner(System.in);
    int N = sc.nextInt();
    int M = sc.nextInt();
    int count =0;
    char[][] A = new char[N][];
    char[][] B = new char[M][];
    for (int i = 0; i <N; i++) A[i] = sc.next().toCharArray();
    for (int i = 0; i <M; i++) B[i] = sc.next().toCharArray();
    for (int i=0; i<N-M+1; i++) {
      L: for (int j=0; j<N-M+1; j++) {
        for (int k=0; k<M; k++) {
          for (int l=0; l<M; l++) {
            if (A[i+k][j+l] != B[k][l]) continue L;
          }
        }
        count =1;
        break;
      } 
    }
    if (count ==1) {
      System.out.println("Yes");
    } else {
      System.out.println("No");
    }
  }
}
