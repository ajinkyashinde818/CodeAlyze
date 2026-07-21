import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        new Main().run();
    }

    int dp[][];
    int[][] A;
    int N;
    int M;
    int X;
    int[] C;

    private void run() {
        Scanner scanner = new Scanner(System.in);
        this.N = scanner.nextInt();
        this.M = scanner.nextInt();
        this.X = scanner.nextInt();

        this.C = new int[N]; // 参考書の値段
        A = new int[N][M]; // アルゴリズムの理解度
        int[] sum = new int[M];

        this.dp = new int[N][500000];

        for (int i = 0; i < N; i++) {
            C[i] = scanner.nextInt();
            for (int j = 0; j < M; j++) {
                A[i][j] = scanner.nextInt();
                sum[j] += A[i][j];
            }
        }

        for (int j = 0; j < M; j++) {
            if (sum[j] < X) {
                System.out.println(-1);
                return;
            }
        }

        // dp
        System.out.println(rec(0, new int[M]));
    }


    private int rec(int i, int[] x) {
        int res;

        boolean flg = true;
        int[] tmp = new int[M];
        int[] tmp_orig = new int[M];
        if(i < N) {
            for (int j = 0; j < M; j++) {
                tmp_orig[j] = x[j];
                tmp[j] = x[j] + A[i][j];
                if (x[j] < X) flg = false;
            }
        }else {
            for (int j = 0; j < M; j++) {
                if (x[j] < X) {
                    flg = false;
                    break;
                }
            }
        }
        res = 0;
        if(i == N && !flg) {
            // 条件を満たさずに最後に到達した
            res = 99999999;
        } else if(flg) {
            // 満たしているので商品を入れる必要がない
            res = 0;
        } else {
            // 入れない場合と入れる場合
            int a = rec(i + 1, tmp_orig);
            int b = rec(i + 1, tmp) + C[i];
            res = Math.min(a, b);
        }
        return res;
    }
}
