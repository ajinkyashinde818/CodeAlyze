/*
String[]の初期化、整数の型がlongになっているか
関数（splitとかcontainsとか）内では"+"とかは正規表現となされるので"\\+"とする
配列のコピーはarr1=arr.clone()
HashSet<>[]はおのおの初期化した？？？？？
負の数の割り算は絶対値が小さいほうに切り捨てられるex.-1/2=0ので、ある値>kみたいな式だとバグらせやすいので注意
ある値>=kとして、切り上げた値をとるべき
toLowerCase()はアルファベット以外に対して行ってもエラーにはならない
ArrayDequeではpopとpushはStackと同じ操作になる
//import static java.lang.System.*; はしばらく使わなそう(使うとしてもexit(0)のためだけ)←return;でよさそう
最後にout.flush()またはout.close()をするのを忘れずに！
Point2D p2d=new Point2D.Double(d1,d2);
//import static java.lang.System.*;
*/
//入力終了→Ctrl+D
import java.util.*;
import java.io.*;
import java.awt.*;
import java.awt.geom.Point2D;
import static java.lang.Math.*;
public class Main{
    public static void main(String[] args) {
        while (true) {
            int n = sc.nextInt();
            if (n == 0) break;
            char[][] c = new char[n][1100];

            for (int i = 0; i < n; i++) {
                String s = sc.next();
                int l = s.length();
                for (int j = 0; j < l; j++) {
                    c[i][j] = s.charAt(j);
                }
                int p = 0;
                while (c[i][p] == '.') p++;
                if (p > 0) c[i][p - 1] = '+';
            }

            for (int i = 0; i < n; i++) {
                if (c[i][0] != '.' && c[i][0] != '+' && c[i][0] != '|') {
                    continue;
                }
                int p = 0;
                int b = i;
                while (c[i][p] != '+') {
                    p++;
                }
                if (p == 0) continue;
                if (c[i - 1][p - 1] == '|') continue;
                while (b < n && c[b][p - 1] == '.') {
                    //out.println(i+" "+b+" "+p+" "+c[b][p-1]+" !!!!!");
                    b++;
                }
                if (b == n || b == i || c[b][p - 1] != '+') continue;
                for (int j = i; j < b; j++) {
                    c[j][p - 1] = '|';
                }
            }

            for (int i = 0; i < n; i++) {
                for (int j = 0; j < 1100; j++) {
                    if ((int) c[i][j] == 0) break;
                    out.print(c[i][j] == '.' ? ' ' : c[i][j]);
                }
                out.println();
            }

        }
        out.close();
    }

    static PrintWriter out = new PrintWriter(System.out);

    static class sc {
        static Scanner s = new Scanner(System.in);

        static String next() {
            return s.next();
        }

        static String nextLine() {
            return s.nextLine();
        }

        static int nextInt() {
            return Integer.parseInt(s.next());
        }

        static long nextLong() {
            return Long.parseLong(s.next());
        }

        static double nextDouble() {
            return Double.parseDouble(s.next());
        }

        static boolean hasNext() {
            return s.hasNext();
        }

        static boolean hasNextInt() {
            return s.hasNextInt();
        }

    }

}
