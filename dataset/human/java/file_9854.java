import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

// 提出時にMainに変更する
public class Main {
    public static void main(String[] args) throws Exception {

        Scanner sc = new Scanner(System.in);

        // 参考書数
        int n = sc.nextInt();

        // 習得したいアルゴリズム数
        int m = sc.nextInt();

        // 習得目標理解度
        int x = sc.nextInt();

        // n番目の参考書の値段
        int[] c = new int[n];

        // n番目の参考書のm番目のアルゴリズムの上昇理解度
        int[][] a = new int[n][m];

        for (int i = 0; i < n; i++) {
            c[i] = sc.nextInt();
            for (int j = 0; j < m; j++) {
                a[i][j] = sc.nextInt();
            }
        }

        int[] aTmp = new int[m];
        int costTmp = 0;
        List<Integer> costsSave = new ArrayList<>();
        boolean masterd = true;

        // bit全探索
        for (int i = 0; i < 1 << n; i++) {
            // 1loop毎にどの参考書を買うかの判定(j冊目を買うかどうか)
            for (int j = 0; j < n; j++) {
                if ((1 & i >> j) == 1) {
                    // ここに引っかかった = 買う対象に追加(j冊目購入)
                    for (int h = 0; h < m; h++) {
                        // j冊目の参考書を買った時のm番目のアルゴリズムの理解度上昇
                        aTmp[h] += a[j][h];
                    }

                    // j冊目の値段
                    costTmp += c[j];
                }
            }

            // 参考書を買い終わったので、アルゴリズムを覚えられたかどうかの判定
            for (int h = 0; h < m; h++) {
                if (aTmp[h] < x) {
                    masterd = false;
                    break;
                }
            }

            // 覚えられた場合は値段を保持
            if (masterd) {
                costsSave.add(costTmp);
            }

            // 後始末
            aTmp = new int[m];
            costTmp = 0;
            masterd = true;
        }

        // listのうち最小の値を出力。リストがnullなら"-1"を出力
        int ans = Integer.MAX_VALUE;
        if (costsSave.isEmpty()) {
            ans = -1;
        } else {
            for (int cost : costsSave) {
                if (ans > cost) {
                    ans = cost;
                }
            }
        }

        System.out.println(ans);
        sc.close();
    }

}
