import java.util.*;

public class Main {
  public static void main(String[] args){
    Scanner in = new Scanner(System.in);

    int N = in.nextInt();
    int M = in.nextInt();
    int X = in.nextInt();
    int ans = -1;

    int[] prices = new int[N];
    int[][] books = new int[N][M];

    for (int i = 0; i < N; i++) {
      prices[i] = in.nextInt();
      for (int j = 0; j < M; j++) {
        books[i][j] = in.nextInt();
      }
    }

    for (int i = 0; i < (1 << N); i++) {
      int p = 0;
      int[] understandings = new int[M];

      for (int j = 0; j < N; j++) {
        if ((i & (1 << j)) > 0) {
          p += prices[j];
          for (int k = 0; k < M; k++) {
            understandings[k] += books[j][k];
          }
        }
      }

      boolean valid = true;
      for (int j = 0; j < M; j++) {
        if (understandings[j] < X) {
          valid = false;
          break;
        }
      }

      if (valid) {
        if (ans == -1) {
          ans = p;
        } else {
          ans = Math.min(ans, p);
        }
      }
    }

    System.out.println(ans);
  }
}
