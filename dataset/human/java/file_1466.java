import java.util.*;

public class Main{
  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
    int n = sc.nextInt();
    int m = sc.nextInt();
    String blank = sc.nextLine();
    char[][] a = new char[n][n];
    char[][] b = new char[m][m];
    boolean flag = false;

    for(int i = 0; i < n; i++){
      String s = sc.nextLine();
      a[i] = s.toCharArray();
    }
    for(int i = 0; i < m; i++){
      String s = sc.nextLine();
      b[i] = s.toCharArray();
    }

    outline:for(int i = 0; i <= n-m; i++){
      for(int j = 0; j <= n-m; j++){
        int cnt = 0;
        for(int k = 0; k < m; k++){
          for(int l = 0; l < m; l++){
            if(a[i+k][j+l] == (b[k][l])){
              cnt++;
            }
          }
        }
        if(cnt == m * m){
          flag = true;
          break outline;
        }
      }
    }

    if(flag){System.out.println("Yes");}
    else{System.out.println("No");}

  }
}
