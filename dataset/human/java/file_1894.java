// 参考 -> 提出 #4178631

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int d = sc.nextInt();
        int g = sc.nextInt();
        int[] p = new int[d];
        int[] c = new int[d];

        for (int i = 0; i < d; i++) {
            p[i] = sc.nextInt();
            c[i] = sc.nextInt();
        }

        System.out.println(dfs(p, c, g, 0, 0, 0, new boolean[d]));
    }

    // 引数(p, c, g, score:現在のスコア, cnt:今まで解いた問題数, point:今調べている問題, isCheck:利用した問題)
    static int dfs(int[] p, int[] c, int g, int score, int cnt, int point, boolean[] isCheck) {
        int min = 100000;

        for (int i = 0; i < p.length; i++) {
            if (isCheck[i])     // すでに利用済みの問題はスキップ
                continue;

            int needScore = g - score;      // 目標値に必要な値
            int num = (i + 1) * 100;    // １問ごとの得点
            // 目標値に到達するために解く必要のある問題数
            int needNum = needScore / num + (needScore % num == 0 ? 0 : 1);

            // 必要な問題数が足りる場合、今まで解いた数に足せばいい
            if (needNum <= p[i]) {
                min = Math.min(min, cnt + needNum);
            }
            // ボーナススコアを合わせることで目標値に到達できるならば、すべて解く
            else if (num * p[i] + c[i] >= needScore) {
                min = Math.min(min, cnt + p[i]);
            }
            // さらに深く探索
            else {
                isCheck[i] = true;
                min = Math.min(min, dfs(p, c, g, score + num * p[i] + c[i], cnt + p[i], i+1, isCheck));
                isCheck[i] = false;
            }
        }

        return min;
    }
}
