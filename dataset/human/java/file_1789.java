import java.io.*;
import java.util.*;
import static java.lang.System.out;

public class Main {
    static MyReader in = new MyReader();

    public static void main(String[] args){
        int D = in.i();
        int G = in.i();
        int[] p = new int[D];
        int[] c = new int[D];
        for (int i = 0; i < D; i++) {
            p[i] = in.i();
            c[i] = in.i();
        }
        int ans = Integer.MAX_VALUE;
        for (int i = 0; i < 1 << D; i++) {
            int t = 0;
            int sum = 0;
            for (int j = 0; j < D; j++) {
                if ((i >> j & 1) == 1) {
                    sum += 100 * (j + 1) * p[j] + c[j];
                    t += p[j];
                }
            }
            for (int j = D - 1; j >= 0; j--) {
                if (G <= sum) {
                    break;
                } else if ((i >> j & 1) == 0){
                    int n = min(p[j] - 1, (G - sum - 1) / (100 * (j + 1)) + 1);
                    t += n;
                    sum += 100 * (j + 1) * n;
                }
            }
            if (G <= sum) {
                ans = min(ans, t);
            }

        }
        out.println(ans);
    }

    static int min(int a, int b) {
        return a < b ? a : b;
    }
}

class MyReader extends BufferedReader {
    char[] cbuf = new char[1024];
    int head = 0;
    int tail = 0;

    MyReader() {
        super(new InputStreamReader(System.in));
    }

    char next() {
        if (head == tail) {
            try {
                tail = read(cbuf, 0, cbuf.length);
            } catch (IOException e) {}
            head = 0;
        }
        return cbuf[head++];
    }

    void back() {
        head--;
    }

    boolean minus() {
        boolean minus;
        while (true) {
            char c = next();
            if (c != ' ' && c != '\n' && c != '\r') {
                if (!(minus = c == '-')) back();
                return minus;
            }
        }
    }

    void skip() {
        while (true) {
            char c = next();
            if (c != ' ' && c != '\n' && c != '\r') {
                back();
                break;
            }
        }
    }

    char[] s(final int N) {
        skip();
        char[] s = new char[N];
        for (int i = 0; i < s.length; i++) {
            s[i] = next();
        }
        return s;
    }

    int i() {
        boolean minus = minus();
        int n = 0;
        while (true) {
            int k = next() - '0';
            if (k < 0 || 9 < k) break;
            n = 10 * n + k;
        }
        return minus ? -n : n;
    }

    int[] ii(final int N) {
        int[] a = new int[N];
        for (int j = 0; j < a.length; j++) a[j] = i();
        return a;
    }

    long l() {
        boolean minus = minus();
        long n = 0;
        while (true) {
            int k = next() - '0';
            if (k < 0 || 9 < k) break;
            n = 10 * n + k;
        }
        return minus ? -n : n;
    }
}
