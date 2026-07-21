import java.util.*;

class Main {
	public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        //入力
        int N = sc.nextInt();
        int M = sc.nextInt();
        int X = sc.nextInt();
        int[] C = new int[N];
        int[][] A = new int[N][M];

        for(int i=0;i<N;i++) {
            C[i] = sc.nextInt();
            for(int j=0;j<M;j++) {
                A[i][j] = sc.nextInt();
            } 
        }

        //出力の値(ダメな時 -1)
        int out = 0;

        //不可能チェック
        boolean check = true;
        //全アルゴリズム別に得点を全て累計
        for(int i=0; i<M; i++) {
            int tmp = 0;
            for(int j=0; j<N; j++) {
                tmp += A[j][i];
            }
            if(tmp < X) {
                check = false;
                break;
            }
        }
        if(check == false) {
            out = -1;
        } else {
            //最小金額の初期値
            int min = 0;
            for(int i=0; i<N; i++) {
                min += C[i];
            }

            //全通り(N冊)
            int ptn = (int)Math.pow(2,N); 
            for(int i=0; i<ptn; i++) {
                int cost = 0;
                int[] score = new int[M];
                for(int j=0; j<N; j++) {
                    if(((i)&(int)Math.pow(2,j)) != 0) {
                        cost += C[j];
                        for(int k=0; k<M; k++) {
                            score[k] += A[j][k];
                        }
                    }
                }
                //scoreチェック
                boolean scheck = true;
                for(int l = 0; l<M; l++) {
                    if(score[l] < X) {
                        scheck = false;
                        break;
                    }
                }
                if(scheck == true) {
                    if(cost < min) {
                        min = cost;
                    }
                }
            }
            out = min;
        }
        // 出力
        System.out.println(out);
        /*int[] score = new int[M];

        for(int i=0;i<N;i++) {
            for(int j=0;j<M;j++) {
                score[j] += A[i][j]; 
                if(score[j] < M) 
                    f = false; //もし，スコアがM以下なら(一つでもあればfalse)
                cost = Math.min(cost,C[i]);
            }
            
        }
        if(f = false) System.out.println(-1);
        else System.out.println(sum);
        */
    }
}
