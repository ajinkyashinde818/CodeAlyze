import java.util.HashMap;
import java.util.Scanner;

/*
問題文

*/

public class Main {
    public static void main(String[] args){

        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        long x = sc.nextInt();

        long[][] input = new long[n][m+1];

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m + 1; j++) {
                input[i][j] = sc.nextInt();
            }
        }

        int ans = 1200001;

        // 2^Nの買う、買わないの全通りを探索する
        for (int i = 0; i < Math.pow(2,n); i++) {
            boolean flg = true;
            int[] arr = new int[m];
            int sum = 0;

            for (int j = 0; j < n; j++) {

                // 買う場合、金額の計算と、この組み合わせの中で
                // アルゴリズムの習熟度がx以上になるかを計算する
                if ((1 & i >> j) == 1) {
                    sum+=input[j][0];   // 金額の計算
                    
					for(int k = 1; k <= m; k++)   // Aj,1 Aj,2  ⋯ Aj,M の縦の足し算
					{
						arr[k-1]+=input[j][k];
					}
                };
            }
            // 合計結果について、一つずつ、x以上となっているか確認
            for (int j = 0; j < m; j++) {
                if (arr[j] < x) {
                    flg = false;
                }    
            }
            // 習熟度がx以上の場合
            if (flg) {
                ans = Math.min(ans, sum);
            }
        }

        if (ans == 1200001) {
            System.out.println("-1");
        } else {
            System.out.println(ans);

        }
    }
}
