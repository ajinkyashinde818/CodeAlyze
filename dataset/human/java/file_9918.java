import java.util.*;

class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int N = sc.nextInt();
    int M = sc.nextInt();
    int X = sc.nextInt();
    int[][] books = new int[N][M+1];
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < M+1; j++) books[i][j] = sc.nextInt();
    }
    int ans = Integer.MAX_VALUE;
    for (int i = 0; i < 1 << N; i++) {
      int[] total = new int[M+1];
      for (int j = 0; j < N; j++) {
        if ((1&i>>j) == 1) {
          for (int k = 0; k < M+1; k++) total[k] += books[j][k];
        }
      }
      if (check(total, X)) ans = Math.min(ans, total[0]);
    }
    System.out.println(ans == Integer.MAX_VALUE ? -1 : ans);
  }
  static boolean check(int[] t, int x) {
    for (int i = 1; i < t.length; i++) {
      if (t[i] < x) return false;
    }
    return true;
  }
}
