import java.util.Scanner;

public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);


    int n = sc.nextInt();  //本
    int m = sc.nextInt();  //アルゴリズムの数
    int x = sc.nextInt();  //理解度の最低ライン
    int[] c = new int[n];
    int[][] a = new int[n][m];

    for (int i = 0; i < n; i++) {
      c[i] = sc.nextInt();
      for (int j = 0; j < m; j++) {
        a[i][j] = sc.nextInt();
      }
    }

    final int INIT_NUM = 10000000;
    int cost = INIT_NUM;
    for (int i = 0; i < (int) Math.pow(2, n); i++) {
      int bin_i = i;
      int[] rikaido = new int[m];
      int total = 0;
      int pos = 0;

      for (int j = 0; j < n; j++) {
        if ((bin_i & 1) == 0) {
          bin_i >>= 1;
          pos++;
          continue;
        }

        total += c[pos];
        for (int k = 0; k < m; k++) {
          rikaido[k] += a[pos][k];
        }
        bin_i >>= 1;
        pos++;
      }

      if (checkRikaido(rikaido, x)) {
        cost = Math.min(cost, total);
      }
    }

    System.out.println(cost != INIT_NUM ? cost : "-1");
  }

  private static boolean checkRikaido(int[] rikaido, int ikichi) {
    for (int i : rikaido) {
      if (i < ikichi) return false;
    }

    return true;
  }
}
