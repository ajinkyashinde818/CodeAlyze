import java.util.*;
import javax.lang.model.util.ElementScanner6;
import java.lang.Math;

public class Main {

    public static void main(final String[] args) {
        final Scanner sc = new Scanner(System.in);

        // 入力
        int n = sc.nextInt();
        int m = sc.nextInt();
        int x = sc.nextInt();
        //String s = sc.next();

        // 処理
        int[] c = new int[n];
        int[][] a = new int[n][m];

        for(int i = 0; i < n; i++){
            c[i] = sc.nextInt();
            for(int j = 0; j < m; j++){
                a[i][j] = sc.nextInt();
            }
        }

        int out = 0;

        //不可能チェック
        boolean check = true;
        for(int i = 0; i < m; i++){
            int tmp = 0;
            for(int j = 0; j < n; j++){
                tmp += a[j][i];
            }
            if(tmp < x){
                check = false;
                break; 
            }
        }
        if(check == false){
            out = -1;
        } else {
            //最小金額の初期値
            int min = 0;
            for(int i = 0; i < n; i++){
                min += c[i];
            }

            //全組み合わせ
            int ptn = (int)Math.pow(2, n);
            for(int i = 0; i < ptn; i++){
                int kingaku = 0;
                int[] score = new int[m];
                for(int j = 0; j < n; j++){
                    if(((i)&((int)Math.pow(2,j))) != 0){
                        kingaku += c[j];
                        for(int k = 0; k < m; k++){
                            score[k] += a[j][k];
                        }
                    }
                }
                //scoreチェック
                boolean scheck = true;
                for(int l = 0; l < m; l++){
                    if(score[l] < x){
                        scheck = false;
                        break;
                    }
                }
                if(scheck == true){
                    if(kingaku < min) {
                        min = kingaku;
                    }
                }
            }
            out = min;
        }

        // 出力
        System.out.println(out);
    }
}
