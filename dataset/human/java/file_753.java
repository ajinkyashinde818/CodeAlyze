import java.util.Scanner;

/**
 * アルゴリズム
 * 10以上： 内部レーティング
 * 10未満： 100×(10−K)
 */

public class Main {
    public static void main(String[] args) {
        // 変数
        int n = 0; // 参加回数
        int r = 0; // 表示レーティング
        int rate = 0; // 内部レーティング

        // 入力値
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        r = sc.nextInt();

        if(n >= 10){
            rate = r;
        } else {
            rate = r + (100 * (10-n));
        }

        // 出力
        System.out.println(rate);
    }
}
