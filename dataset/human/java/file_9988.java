import java.util.Arrays;
import java.util.Scanner;

public class Main {

  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int n = sc.nextInt();
    int m = sc.nextInt();
    int x = sc.nextInt();
    int[][] books = new int[n][m + 1];
    for (int i = 0; i < n; i++) {
      books[i][0] = sc.nextInt();
      for (int j = 1; j <= m; j++) {
        books[i][j] = sc.nextInt();
      }
    }
    int answer = -1;
    int[] scores = new int[m];
    for (int sw = 1; sw <= (1 << n); sw++) {
      Arrays.fill(scores, 0);
      int amount = 0;
      for (int index = 0; index < n; index++) {
        if ((1 & (sw >> index)) == 1) {
          for(int i = 0; i < m; i++){
            scores[i] += books[index][i + 1];
          }
          amount += books[index][0];
        }
      }
      boolean isOK = true;
      for(int i = 0; i < scores.length; i++){
        if(scores[i] < x){
          isOK = false;
          break;
        }
      }
      if(isOK){
        if(answer < 0){
          answer = amount;
        } else {
          answer = Math.min(answer, amount);
        }
      }
    }
    System.out.println(answer);
  }
}
