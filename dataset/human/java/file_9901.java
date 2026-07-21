import java.util.*;
class Main {
  final static int INF = 1001001001;

  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);

    // 入力データを変数に格納する
    int n = sc.nextInt();
    int m = sc.nextInt();
    int x = sc.nextInt();
    int[][] a = new int[12][12];
    int[] c = new int[n];
    for (int i = 0; i < n; i++) {
      c[i] = sc.nextInt();
      for (int j = 0; j < m; j++) {
        a[i][j] = sc.nextInt();
      }
    }
    sc.close();

    // 回答=コストの最小値なので最小値比較のために大きな数値で初期化しておく。
    int ans = INF;

    // 全ての組み合わせパターンをチェックする
    for (int s = 0; s < 1<<n; s++) {
      int cost = 0;         // このs番目の組み合わせのコスト
      int[] d = new int[m]; // このs番目の組み合わせでの各アルゴリズムの理解度

      // ２進数で各ビットが1になっているかどうか調べる
      for (int i = 0; i < n; i++) {

        // 右からi番目のビットが1になっていれば、購入する参考書としてコストとアルゴリズムを加算する
        if ( (s & 1<<i) == 1<<i) {
          // コストを足す
          cost += c[i];

          // 各アルゴリズムの理解度に足す
          for (int j = 0; j < m; j++) {
            d[j] += a[i][j];
          }
        }
      }

      // 全てのアルゴリズムの理解度がxを超えているかチェックする
      boolean ok = true;
      for (int j = 0; j < m; j++) {
        if (d[j] < x) ok = false; // １つでもx未満があれば。
      }
      // チェックOKであれば、そのコストが最小値を更新するかどうか。
      if (ok) ans = Math.min(ans, cost);

    }

    // 全てのアルゴリズムの理解度がxを超えるパターンが１つもない場合はansがINFのままになってる
    if (ans == INF) System.out.println(-1);
    else System.out.println(ans);

  }
}
