import java.util.*;
public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int N = sc.nextInt();
    int M = sc.nextInt();
    char[][] A = new char[N][N];
    char[][] B = new char[M][M];
    for(int i=0;i<N;i++){
      String n = sc.next();
      for(int j=0;j<N;j++){
        A[i][j]=n.charAt(j);
      }
    }
    for(int i=0;i<M;i++){
      String m = sc.next();
      for(int j=0;j<M;j++){
        B[i][j]=m.charAt(j);
      }
    }
    for(int i=0;i<N;i++){
      for(int j=0;j<N;j++){
        if(i+M>N || j+M>N){
          break;
        }
        boolean match = true;
        for(int k=0;k<M;k++){
          for(int l=0;l<M;l++){
            if(A[i+k][j+l]!=B[k][l]){
              match = false;
              break;
            }
          }
        }
        if(match){
          System.out.println("Yes");
          return;
        }
      }
    }
    System.out.println("No");
  }
}
