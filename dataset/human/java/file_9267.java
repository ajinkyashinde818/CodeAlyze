import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.util.NoSuchElementException;

public class Main {

    static PrintWriter out;
    static InputReader sc;

    static final int MOD = 1000000007;

    static void solve() {
        int N = sc.nextInt();
        int M = sc.nextInt();
        int[] dp = new int[N + 1];
        Arrays.fill(dp, -1);
        dp[0] = 1;
        for (int i = 0; i < M; i++) {
            dp[sc.nextInt()] = 0;
        }
        for (int i = 1; i <= N; i++) {
            if (dp[i] == -1) {
                if (i != 1) {
                    dp[i] = dp[i - 1] + dp[i - 2];
                    dp[i] %= MOD;
                } else {
                    dp[i] = dp[i - 1];
                    dp[i] %= MOD;
                }
            }
        }
        out.println(dp[N]);
    }

    public static void main(String[] args) {
        sc = new InputReader(System.in);
        out = new PrintWriter(System.out);
        solve();
        out.flush();
    }

    public static class ArraysFillEx {

        public static void fill(Object array, Object value) {

            // 第一引数が配列か判定
            Class<?> type = array.getClass();
            if (!type.isArray()) {
                throw new IllegalArgumentException("not array");
            }

            // クラスの型を判定
            String arrayClassName = array.getClass().getSimpleName().replace("[]", "").toLowerCase();
            String valueClassName = value.getClass().getSimpleName().toLowerCase().replace("character", "char")
                    .replace("integer", "int");
            if (!arrayClassName.equals(valueClassName)) {
                throw new IllegalArgumentException("does not match");
            }

            // 処理
            if (type.getComponentType().isArray()) {
                for (Object o : (Object[]) array) {
                    fill(o, value);
                }
            } else if (array instanceof boolean[]) {
                Arrays.fill((boolean[]) array, (boolean) value);
            } else if (array instanceof char[]) {
                Arrays.fill((char[]) array, (char) value);
            } else if (array instanceof byte[]) {
                Arrays.fill((byte[]) array, (byte) value);
            } else if (array instanceof short[]) {
                Arrays.fill((short[]) array, (short) value);
            } else if (array instanceof int[]) {
                Arrays.fill((int[]) array, (int) value);
            } else if (array instanceof long[]) {
                Arrays.fill((long[]) array, (long) value);
            } else if (array instanceof float[]) {
                Arrays.fill((float[]) array, (float) value);
            } else if (array instanceof double[]) {
                Arrays.fill((double[]) array, (double) value);
            } else {
                Arrays.fill((Object[]) array, value);
            }
        }

    }

    static class InputReader {

        private InputStream in;
        private byte[] buffer = new byte[1024];
        private int curbuf;
        private int lenbuf;

        public InputReader(InputStream in) {
            this.in = in;
            this.curbuf = this.lenbuf = 0;
        }

        public boolean hasNextByte() {
            if (this.curbuf >= this.lenbuf) {
                this.curbuf = 0;
                try {
                    this.lenbuf = this.in.read(this.buffer);
                } catch (IOException e) {
                    throw new InputMismatchException();
                }
                if (this.lenbuf <= 0) {
                    return false;
                }
            }
            return true;
        }

        private int readByte() {
            if (this.hasNextByte()) {
                return this.buffer[this.curbuf++];
            } else {
                return -1;
            }
        }

        private boolean isSpaceChar(int c) {
            return !(c >= 33 && c <= 126);
        }

        private void skip() {
            while (this.hasNextByte() && this.isSpaceChar(this.buffer[this.curbuf])) {
                this.curbuf++;
            }
        }

        public boolean hasNext() {
            this.skip();
            return this.hasNextByte();
        }

        public String next() {
            if (!this.hasNext()) {
                throw new NoSuchElementException();
            }
            StringBuilder sb = new StringBuilder();
            int b = this.readByte();
            while (!this.isSpaceChar(b)) {
                sb.appendCodePoint(b);
                b = this.readByte();
            }
            return sb.toString();
        }

        public int nextInt() {
            if (!this.hasNext()) {
                throw new NoSuchElementException();
            }
            int c = this.readByte();
            while (this.isSpaceChar(c)) {
                c = this.readByte();
            }
            boolean minus = false;
            if (c == '-') {
                minus = true;
                c = this.readByte();
            }
            int res = 0;
            do {
                if (c < '0' || c > '9') {
                    throw new InputMismatchException();
                }
                res = res * 10 + c - '0';
                c = this.readByte();
            } while (!this.isSpaceChar(c));
            return minus ? -res : res;
        }

        public long nextLong() {
            if (!this.hasNext()) {
                throw new NoSuchElementException();
            }
            int c = this.readByte();
            while (this.isSpaceChar(c)) {
                c = this.readByte();
            }
            boolean minus = false;
            if (c == '-') {
                minus = true;
                c = this.readByte();
            }
            long res = 0;
            do {
                if (c < '0' || c > '9') {
                    throw new InputMismatchException();
                }
                res = res * 10 + c - '0';
                c = this.readByte();
            } while (!this.isSpaceChar(c));
            return minus ? -res : res;
        }

        public double nextDouble() {
            return Double.parseDouble(this.next());
        }

        public int[] nextIntArray(int n) {
            int[] a = new int[n];
            for (int i = 0; i < n; i++) {
                a[i] = this.nextInt();
            }
            return a;
        }

        public long[] nextLongArray(int n) {
            long[] a = new long[n];
            for (int i = 0; i < n; i++) {
                a[i] = this.nextLong();
            }
            return a;
        }

        public char[][] nextCharMap(int n, int m) {
            char[][] map = new char[n][m];
            for (int i = 0; i < n; i++) {
                map[i] = this.next().toCharArray();
            }
            return map;
        }
    }

    static void tr(Object... o) {
        out.println(Arrays.deepToString(o));
    }
}
