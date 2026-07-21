import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        // 参考書数
        int n = sc.nextInt();
        // アルゴリズム数
        int m = sc.nextInt();
        // すべてのアルゴリズム理解度
        int x = sc.nextInt();
        // 参考書の金額
        int[] c = new int[n];
        // アルゴリズムの理解度
        int[][] a = new int[n][m];
        // 入力
        for(int i=0; i<n; i++) {
            c[i] = sc.nextInt();
            for(int j=0; j<m; j++) {
                a[i][j] = sc.nextInt();
            }
        }

        // 参考書の合計金額のリスト
        List<Integer> list = new ArrayList<>();

        // 参考書の全パターンのループ、bit全探索の全通り
        // for (int i = 0; i < 1 << n; i++)でもいい
        for (int i = 0; i < Math.pow(2,n); i++) {
            // m番目のアルゴリズムの理解度の合計
            int[] aTotal = new int[m];
            // 参考書の合計金額
            int cTotal = 0;
            // 各参考書のループ
            for (int j = 0; j < n; j++) {
                // 最下桁が1かどうかを判定
                // 1だったら購入の対象
                if ((i >> j & 1) == 1) {
                    for(int k=0; k<m; k++) {
                        // アルゴリズム理解度の合計
                        aTotal[k] += a[j][k];
                    }
                    // 参考書金額の合計
                    cTotal += c[j];
                }
            }

            // アルゴリズムを覚えたかどうか
            boolean isMastered = true;
            // 参考書を買い終わったので、アルゴリズムを覚えられたかどうかの判定
            for(int k=0; k<m; k++) {
                if(aTotal[k] < x) {
                    isMastered = false;
                    break;
                }
            }
            // アルゴリズムを覚えた場合は参考書の合計金額をlistについか
            if(isMastered) {
                list.add(cTotal);
            }
        }
        // アルゴリズムを１つも覚えていない場合は-1、覚えた場合最小値
        if(list.size() < 1) {
            System.out.println(-1);
        } else {
            Collections.sort(list);
            System.out.println(list.get(0));
        }
    }
}
