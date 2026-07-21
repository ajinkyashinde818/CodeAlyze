import java.util.*;

public class Main {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        // 入力
        int n = sc.nextInt();
        long k = sc.nextLong();

        int[] a = new int[n+1];
        for (int i = 1; i <= n; i++) {
            a[i] = sc.nextInt();
        }

        long zan = k;
        // 1 6 2 5 3 2 5 3 [2]...
        long[] check = new long[n+1];
        int t = 1;
        for (long j = 1; j <= k; j++) {
            if (check[t] == 2) {
                // ループし始めている
                break;
            }
            check[t]++;
            t = a[t];
            zan--;
        }

        if (zan > 0) {
            // 何回移動すれば同じ場所に戻るか
            long loopTerms = 0;
            for (int i = 1; i <= n; i++) {
                if (check[i] == 2) {
                    loopTerms++;
                }
            }

            long k2 = zan % loopTerms;
            for (long j = 1; j <= k2; j++) {
                t = a[t];
            }
        }

        // 出力
        System.out.println(t);
    }
}
