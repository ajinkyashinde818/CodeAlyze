import java.util.*;
public class Main {

  public static void main(String[] args) { 
      Scanner sc = new Scanner(System.in);
      int n = sc.nextInt();
      int m = sc.nextInt();
      char[][] grid = new char[n][n];
      for(int i = 0; i < n; i++)
        grid[i] = sc.next().toCharArray();

      char[][] template = new char[m][m];
      for(int i = 0; i < m; i++)
        template[i] = sc.next().toCharArray();

      for(int i = 0; i < n - m + 1; i++) {
        loop:
        for(int j = 0; j < n - m + 1; j++) {
          for(int ti = 0; ti < m; ti++) {
            for(int tj = 0; tj < m; tj++) {
              if(template[ti][tj] != grid[i + ti][j + tj])
                continue loop;
            }
          }
          System.out.println("Yes");
          return;
        }
      } 
      System.out.println("No");
  }
}
