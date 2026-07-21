import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        int N = 0;
        int M = 0;
        int mod = 1000000007;
        int[] StarNum = null;
        try (Scanner sc = new Scanner(System.in)) {
            N = (sc.nextInt()) +1;
            M = sc.nextInt();
            //0でオール初期化
            StarNum = new int[N];
            for (int i = 0; i < M; i++) {
                //壊れている段数は
                int m = sc.nextInt();
                //-1で初期化
                StarNum[m] = -1;
            }
        }
        for (int i = 0; i < N; i++) {
            if (StarNum[i] == -1 && StarNum[i + 1] == -1) {
                //連続して壊れていたら解なし
                System.out.println(0);
                return;
            }
        }
        //0段目と1段目を初期化
        StarNum[0] = 1;
        if (StarNum[1] != -1) {
            StarNum[1] = 1;
        }
        //N段目の組み合わせを計算する
        for (int i = 2; i < N; i++) {
            if (StarNum[i] == -1) {
                //壊れているなら計算しない
                continue;
            }
            //1段前の組み合わせの数
            int a = 0;
            //2段前の組み合わせの数1
            int b = 0;
            if (StarNum[i - 1] != -1) {
                a = StarNum[i - 1];
            }
            if (StarNum[i - 2] != -1) {
                b = StarNum[i - 2];
            }
            //足し合わせた数がその段までに幾組み合わせの数
            //とりあえず1000000007こいつで割ったあまりを使用する
            StarNum[i] = (a + b) % mod;
        }
        //最後にN段目の数を出して終了
        System.out.println(StarNum[N-1]);

    }

}
