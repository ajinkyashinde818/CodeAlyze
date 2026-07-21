import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

public class Main {

    static final String OK = "OK";
    static final String NG = "NG";
    static final String TBD = "TBD";

    static void solve() {
        String s = nextString();
        String t = nextString();

        List<Character> ss = new ArrayList<>();
        List<Character> tt = new ArrayList<>();
        for (int i = 0; i < s.length(); i++) {
            ss.add(s.charAt(i));
        }
        for (int i = 0; i < t.length(); i++) {
            tt.add(t.charAt(i));
        }

        ss.sort((e1, e2) -> e1 - e2);
        tt.sort((e1, e2) -> e2 - e1);

        int minLength = Math.min(s.length(), t.length());
        String result = TBD;
        for (int i = 0; i < minLength; i++) {
            if (ss.get(i) < tt.get(i)) {
                result = OK;
                break;
            } else if (ss.get(i) > tt.get(i)) {
                result = NG;
                break;
            } else {
                result = TBD;
                // not break;
            }
        }

        if (result.equals(TBD)) {
            if (s.length() < t.length()) {
                result = OK;
            } else {
                result = NG;
            }
        }

        if (result.equals(OK)) {
            out.println("Yes");
        } else {
            out.println("No");
        }
    }

    static PrintWriter out;
    static Scanner sc;

    static int[][] newIntArray(int h, int w, int value) {
        int[][] ret = new int[h][w];
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                ret[i][j] = value;
            }
        }
        return ret;
    }

    static int nextInt() {
        return Integer.parseInt(sc.next());
    }

    static long nextLong() {
        return Long.parseLong(sc.next());
    }

    static String nextString() {
        return sc.next();
    }

    static int[] nextIntArray(int n) {
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = nextInt();
        }
        return a;
    }

    static List<Integer> nextIntList(int n) {
        List<Integer> list = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            list.add(nextInt());
        }
        return list;
    }

    static List<Long> nextLongList(int n) {
        List<Long> list = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            list.add(nextLong());
        }
        return list;
    }

    static char[][] nextCharArray(int h, int w) {
        char[][] c = new char[h][w];
        for (int i = 0; i < h; i++) {
            String str = nextString();
            for (int j = 0; j < w; j++) {
                c[i][j] = str.charAt(j);
            }
        }
        return c;
    }

    static <T extends Comparable<? super T>> void sort(List<T> list) {
        Collections.sort(list);
    }

    // greatest common divisor
    static long gcd(long a, long b) {
        if (b == 0) {
            return a;
        }
        return gcd(b, a % b);
    }

    // baseのn乗を計算を返す
    static int pow(int base, int n) {
        int ret = 1;
        for (int i = 0; i < n; i++) {
            ret *= base;
        }
        return ret;
    }

    // return n^k mod m
    static long powMod(long n, long k, long m) {
        if (k == 0) {
            return 1;
        } else if (k % 2 == 1) {
            return powMod(n, k - 1, m) * n % m;
        } else {
            long tmp = powMod(n, k / 2, m);
            return tmp * tmp % m;
        }
    }

    // intをlength桁のbit文字列に変換
    static String toBinaryString(int input, int length) {
        return toBinaryString(input).substring(29 - length);
    }

    // intを29桁のbit文字列に変換
    static String toBinaryString(int input) {
        String ret = "";
        int max = 0x10000000;
        for (int i = 0; i < 29; i++) {
            int tmp = input / max;
            ret += tmp;
            input %= max;
            max /= 2;
        }
        return ret;
    }

    public static void main(String[] args) {
        out = new PrintWriter(System.out);
        sc = new Scanner(System.in);

        solve();

        out.flush();
        sc.close();
    }

}
