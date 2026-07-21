import java.util.*;

public class Main {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        // 入力
        int n = sc.nextInt();
        int m = sc.nextInt();
        int x = sc.nextInt();

        int[] c = new int[n+1];
        int[][] a = new int[n+1][m+1];
        for (int i = 0; i < n; i++) {
            c[i]= sc.nextInt();
            for (int j = 0; j < m; j++) {
                a[i][j] = sc.nextInt();
            }
        }

        int ans = 12345678;
        int all = 1<<n;
        // 000...0（n桁） から 111...1（n桁） までループ(bit全探索)
        for (int mask = 0; mask < all; mask++) {
            int[] level = new int[m];
            int cost = 0;
            for (int i = 0; i < n; i++) {
                // 各ビットでループさせて1の場合足し込む
                if (((mask>>i) & 0x1) == 1) {
                    cost += c[i];
                    for (int j = 0; j < m; j++) {
                        level[j] += a[i][j];
                    }
                }
            }
            boolean ok = true;
            for (int j = 0; j < m; j++) {
                if (level[j] < x) {
                    ok = false;
                }
            }
            if (ok) {
                ans = Math.min(ans, cost);
            }
        }
        if(ans == 12345678) {
            // 出力
            System.out.println(-1);
        } else {
            // 出力
            System.out.println(ans);
        }
    }
}
