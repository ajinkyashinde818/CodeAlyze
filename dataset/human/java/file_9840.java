import java.util.Scanner;

public class Main {
    static Scanner sc = new Scanner(System.in);
    static int N = sc.nextInt();
    static int M = sc.nextInt();
    static int X = sc.nextInt();
    static int price[] = new int[N];
    static int al[][] = new int[N][M];



    public static void main(String[] args) {
        //標準入力を取得
        for (int i = 0; i < N; i++){
            price[i] = sc.nextInt();
            for (int j = 0; j < M; j++){
                al[i][j] = sc.nextInt();
            }
        }
        int result = 10000000;
        //bit全探索
        for (int bit = 0; bit < (1<<N); bit++){
            int cost = 0;
            int level[] = new int[M];
            for (int i = 0; i < N; i++){
                //bitが1だったら
                if ((bit>>i&1) == 1){
                    //本の値段を足して
                    cost += price[i];
                    for (int j = 0; j < M; j++){
                        //アルゴリズムレベルを上げる
                        level[j] += al[i][j];
                    }
                }
            }
            boolean check = true;
            //確認
            for (int i = 0; i < M; i++){
                if (level[i] < X) check = false;
            }
            if (check){
                result = Math.min(result, cost);
            }
        }

        if (result != 10000000){
            System.out.println(result);
        } else {
            System.out.println(-1);
        }
    }

}
