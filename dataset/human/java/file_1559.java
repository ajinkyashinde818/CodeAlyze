import java.util.*;

public class Main{
  public static void main(String[]args){
    Scanner sc = new Scanner(System.in);
    String[] S = sc.nextLine().split(" ");
    int N = Integer.parseInt(S[0]);
    int M = Integer.parseInt(S[1]);
    
    char[][] a = new char[N][N];
    for(int i = 0; i < N; i++){
      String T = sc.nextLine();
      for(int j = 0; j < N; j++){
        a[i][j] = T.charAt(j);
      }
    }
    
    char[][] b = new char[M][M];
    for(int i = 0; i < M; i++){
      String T = sc.nextLine();
      for(int j = 0; j < M; j++){
        b[i][j] = T.charAt(j);
      }
    }
    
    String ans = "No";
    g : for(int i = 0; i < N-M+1; i++){
      f : for(int j = 0; j < N-M+1; j++){
        for(int k = 0; k < M; k++){
          for(int l = 0; l < M; l++){
            if(b[k][l] != a[k+i][l+j]){
              continue f;
            }
          }
        }
        ans = "Yes";
        break g;
      }
    }
    System.out.println(ans);
  }
}
