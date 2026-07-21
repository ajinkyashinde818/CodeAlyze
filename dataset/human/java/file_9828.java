import java.util.Scanner;

public class Main {
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        int x = sc.nextInt();

        int[] price = new int[n];
        int[][] skillUpValue = new int[n][m];

        for(int i = 0; i < n; i++){//多次元配列の生成（長さnの配列、配列の各要素はmの配列）
            price[i] = sc.nextInt();//値段の配列の生成
            for(int k = 0; k < m; k++){
                skillUpValue[i][k] = sc.nextInt();
            }
        }

        int min = (int)12e6;
        out:for(int i = 0; i < (1<<n);i++){//2進数に見立ててN冊の本の買い方を全探索（2^n-1までやれば全探索になっている）
            int rikai[] = new int[m];
            int cost = 0;
            for(int j = 0;j < n ;j++) {//各n桁の2進数iについて、1〜n桁目を見ていく
                if ((i >> j & 1) == 1) {//iの、j+1桁目が1かどうか判定 → 1なら該当の本を購入している
                    for (int k = 0; k < m; k++) {
                        rikai[k] += skillUpValue[j][k];//1〜Mまでの各アルゴリズムの理解度に本から得られる理解度を計上
                    }
                    cost += price[j];//購入した本の代金をコストに計上
                }
            }

            for(int l = 0; l < m;l++){
                if(rikai[l] < x){
                    continue out;
                }
            }
            if(min > cost) {
                min = cost;
            }
        }
        System.out.println(min == (int)12e6 ? -1 : min);
    }
}
