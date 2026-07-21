import java.util.Scanner;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class Main {

  public static void main(String[] args) {

    Scanner scan = new Scanner(System.in);

    int n = scan.nextInt();
    int m = scan.nextInt();
    int x = scan.nextInt();

    int[] c = new int[n];
    int[][] a = new int[n][m];

    for (int i = 0; i < n; i++) {
      c[i] = scan.nextInt();
      for (int j = 0; j < m; j++) {
        a[i][j] = scan.nextInt();
      }
    }

    int[] ability = new int[m];
    int min = Integer.MAX_VALUE;

    for (int bit = 0; bit < Math.pow(2, n); ++bit) {
      
      for (int i = 0; i < m; i++) {
        ability[i] = 0;
      }
      
      boolean flag = true;
      int money = 0;
      
      for (int i = 0; i < n; ++i) {
        if ((1 & (bit >> i)) == 1) { // i が bit に入るかどうか
          for (int j = 0; j < m; j++) {
            ability[j] += a[i][j];
          }
          money += c[i];
        }
      }
      
      for (int j = 0; j < m; j++) {
        if (ability[j] < x) {
          flag = false;
          break;
        }
      }

      if (flag == true) {
        min = Math.min(money, min);
      }

    }
    
    if(min == Integer.MAX_VALUE) {
      System.out.println(-1);
    } else {
      System.out.println(min);
    }
    
  }

}
