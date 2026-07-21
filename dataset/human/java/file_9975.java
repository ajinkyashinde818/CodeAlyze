import java.util.Scanner;

public class Main {

  public static void main(String[] args) {

    Scanner sc = new Scanner(System.in);
    int n = sc.nextInt();
    int m = sc.nextInt();
    int x = sc.nextInt();

    // テーブルを作成
    int[] c = new int[n];
    int[][] a = new int[n][m];
    for (int i = 0; i < n; i++) {
      c[i] = sc.nextInt();
      for (int j = 0; j < m; j++) {
        a[i][j] = sc.nextInt();
      }
    }

    int answer = Integer.MAX_VALUE;
    for (int i = 0; i < (Math.pow(2, n)); i++) {
      int[] score = new int[m];
      int amount = 0;
      for (int j = 0; j < n; j++) {
        if ((1 & i >> j) == 1) {
          amount += c[j];
          for (int k = 0; k < m; k++) {
            score[k] += a[j][k];
          }
        }
      }

      boolean b = true;
      for (int s : score) {
        if (s < x) {
          b = false;
          break;
        }
      }
      if (b && amount < answer) {
        answer = amount;
      }
    }

    System.out.println(answer == Integer.MAX_VALUE ? -1 : answer);
  }
}
