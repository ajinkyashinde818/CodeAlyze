import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.NoSuchElementException;

/**
 * Created by jaga on 9/22/16.
 */
public class Main{
    public static void solve(PrintWriter out, FastScanner in){
        //逆向きの文字列を考えてみる
        //dream dreamer erase eraser
        //maerd remaerd esare resare
        //最初の三文字で判定可能！
        String S = in.next();
        char c[] = S.toCharArray();
        char cr[] = new char[c.length];
        for(int i = 0;i < c.length;i++) {
            cr[i] = c[c.length - 1 - i];
        }

        S = String.valueOf(cr);

        int idx = 0;
        while (idx <S.length() - 1 ) {
            String str3 = S.substring(idx, idx + 3);
            String str5 = S.substring(idx, idx + 5);


            if (str3.equals("mae")) {
                if (str5.equals("maerd")) {
                    idx += 5;
                } else {
                    System.out.println("NO");
                    return;
                }
            } else if (str3.equals("rem")) {
                String str7 = S.substring(idx, idx + 7);
                if (str7.equals("remaerd")) {
                    idx += 7;
                } else {
                    System.out.println("NO");
                    return;
                }

            } else if (str3.equals("esa")) {
                if (str5.equals("esare")) {
                    idx += 5;
                } else {
                    System.out.println("NO");
                    return;
                }
            } else if (str3.equals("res")) {
                String str6 = S.substring(idx, idx + 6);
                if (str6.equals("resare")) {
                    idx += 6;
                } else {
                    System.out.println("NO");
                    return;
                }
            } else {
                System.out.println("NO");
                return;
            }
        }
        System.out.println("YES");

    }

    static class Pair implements Comparable {
        int first, second;

        Pair(int a, int b) {
            first = a;
            second = b;
        }

        public int compareTo(Object other) {
            Pair p1 = (Pair) other;
            return this.first - ((Pair) other).first; // IDの値に従い昇順で並び替えたい場合
//         return -(this.first - ((Pair) other).first); // IDの値に従い降順で並び替えたい場合
        }
    }

    /*以下はテンプレ*/
    public static void main(String args[]) {
        OutputStream outputStream = System.out;
        PrintWriter out = new PrintWriter(outputStream);
        FastScanner in = new FastScanner();
        solve(out, in);
        out.close();

    }

    public static class FastScanner {
        private final InputStream in = System.in;
        private final byte[] buffer = new byte[1024];
        private int ptr = 0;
        private int bufferLength = 0;

        private boolean hasNextByte() {
            if (ptr < bufferLength) {
                return true;
            } else {
                ptr = 0;
                try {
                    bufferLength = in.read(buffer);
                } catch (IOException e) {
                    e.printStackTrace();
                }
                if (bufferLength <= 0) {
                    return false;
                }
            }
            return true;
        }

        private int readByte() {
            if (hasNextByte()) return buffer[ptr++];
            else return -1;
        }

        private static boolean isPrintableChar(int c) {
            return 33 <= c && c <= 126;
        }

        private void skipUnprintable() {
            while (hasNextByte() && !isPrintableChar(buffer[ptr])) ptr++;
        }

        boolean hasNext() {
            skipUnprintable();
            return hasNextByte();
        }

        public String next() {
            if (!hasNext()) throw new NoSuchElementException();
            StringBuilder sb = new StringBuilder();
            int b = readByte();
            while (isPrintableChar(b)) {
                sb.appendCodePoint(b);
                b = readByte();
            }
            return sb.toString();
        }

        long nextLong() {
            if (!hasNext()) throw new NoSuchElementException();
            long n = 0;
            boolean minus = false;
            int b = readByte();
            if (b == '-') {
                minus = true;
                b = readByte();
            }
            if (b < '0' || '9' < b) {
                throw new NumberFormatException();
            }
            while (true) {
                if ('0' <= b && b <= '9') {
                    n *= 10;
                    n += b - '0';
                } else if (b == -1 || !isPrintableChar(b)) {
                    return minus ? -n : n;
                } else {
                    throw new NumberFormatException();
                }
                b = readByte();
            }
        }

        double nextDouble() {
            return Double.parseDouble(next());
        }

        double[] nextDoubleArray(int n) {
            double[] array = new double[n];
            for (int i = 0; i < n; i++) {
                array[i] = nextDouble();
            }
            return array;
        }

        double[][] nextDoubleMap(int n, int m) {
            double[][] map = new double[n][];
            for (int i = 0; i < n; i++) {
                map[i] = nextDoubleArray(m);
            }
            return map;
        }

        public int nextInt() {
            return (int) nextLong();
        }

        public int[] nextIntArray(int n) {
            int[] array = new int[n];
            for (int i = 0; i < n; i++) array[i] = nextInt();
            return array;
        }

        public long[] nextLongArray(int n) {
            long[] array = new long[n];
            for (int i = 0; i < n; i++) array[i] = nextLong();
            return array;
        }

        public String[] nextStringArray(int n) {
            String[] array = new String[n];
            for (int i = 0; i < n; i++) array[i] = next();
            return array;
        }

        public char[][] nextCharMap(int n) {
            char[][] array = new char[n][];
            for (int i = 0; i < n; i++) array[i] = next().toCharArray();
            return array;
        }

        public int[][] nextIntMap(int n, int m) {
            int[][] map = new int[n][];
            for (int i = 0; i < n; i++) {
                map[i] = nextIntArray(m);
            }
            return map;
        }
    }
}
