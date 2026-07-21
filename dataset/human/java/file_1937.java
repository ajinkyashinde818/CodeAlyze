import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Scanner;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 *
 * @author silviase
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        Scanner in = new Scanner(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        CAllGreen solver = new CAllGreen();
        solver.solve(1, in, out);
        out.close();
    }

    static class CAllGreen {
        public void solve(int testNumber, Scanner in, PrintWriter out) {

            int d = in.nextInt();
            int g = in.nextInt();
            Pair[] p = new Pair[d];
            for (int i = 0; i < d; i++) {
                p[i] = new Pair(in.nextInt(), in.nextInt());
            }

            int res = Integer.MAX_VALUE;

            // 解きかけの問題はどうせ一つしかない
            // ふたつ解きかけにする状況が必要ないから(得点が大きいほうに寄せていけばいいから)
            //　総合スコアをG点以上にすることは可能である。　という条件から,とりあえずd bitの問題を立てて考えればよさそう.

            // 使っていない残りの問題からひとつ選んで必要な分量だけ…？
            // それならソートしておけばよさそう
            // そしたら使ってないものの中から一番前をとればいい
            // 足りなければfalse

            for (int i = 0; i < Math.pow(2, d); i++) {
                int tmpRes = 0;
                int type = i;
                boolean[] fullSolved = new boolean[d];
                int scoreGotByFullSolve = 0;
                for (int j = 0; j < d; j++) {
                    fullSolved[j] = type % 2 == 1;
                    type /= 2;
                    if (fullSolved[j]) {
                        scoreGotByFullSolve += (j + 1) * 100 * p[j].x + p[j].y;
                        tmpRes += p[j].x;
                    }
                }

            /*
            out.println(Arrays.toString(fullSolved));
            out.println("nowScore : " + scoreGotByFullSolve);
            
             */

                if (scoreGotByFullSolve < g) {
                    // score が足りていないので,falseの中から最大のものを選ぶことにする
                    for (int j = fullSolved.length - 1; j >= 0; j--) {
                        boolean b = fullSolved[j];
                        if (!b && scoreGotByFullSolve + p[j].x * (j + 1) * 100 >= g) {
                            tmpRes += (g - scoreGotByFullSolve + (j + 1) * 100 - 1) / (100 * (j + 1));
                            scoreGotByFullSolve = g;
                            break;
                        }
                    }
                }


                if (scoreGotByFullSolve >= g) {
                    res = Math.min(res, tmpRes);
                }

            }
            out.println(res);
        }

    }

    static class Pair {
        public int x;
        public int y;

        public Pair(int x, int y) {
            this.x = x;
            this.y = y;
        }

    }
}
