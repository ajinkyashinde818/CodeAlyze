import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Set;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 *
 * @author Spandan Mishra
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        DTeleporter solver = new DTeleporter();
        solver.solve(1, in, out);
        out.close();
    }

    static class DTeleporter {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.readInt();
            long k = in.readLong();
            int[] a = new int[n + 1];
            for (int i = 1; i <= n; i++)
                a[i] = in.readInt();

            List<Integer> ls = new ArrayList<>();
            Set<Integer> set = new HashSet<>();
            ls.add(1);
            set.add(1);
            int offset = 0;
            int curr = 1;

            while (!set.contains(a[curr])) {
                curr = a[curr];
                ls.add(curr);
                set.add(curr);
            }
//        System.out.println(ls);
//        System.out.println(set);


            if (a[curr] != 1)
                offset = ls.indexOf(a[curr]);

//        System.out.println(offset);

            long cycleLen = ls.size() - offset;
            List<Integer> tmp = new ArrayList<>();

            //remove offset number of elements

            for (int i = 0; i < offset; i++)
                tmp.add(ls.remove(0));

//        System.out.println(tmp);

            //shift back
            if (k < offset)
                System.out.println(tmp.get((int) k));
            else {
                k -= offset;
                k = k % cycleLen;

                // final index
                int index = (int) (k);
                System.out.println(ls.get(index));
            }

        }

    }

    static class InputReader {
        private InputStream stream;
        private byte[] buf = new byte[1024];
        private int curChar;
        private int numChars;

        public InputReader(InputStream stream) {
            this.stream = stream;
        }

        public int read() {
            if (numChars == -1)
                throw new RuntimeException();
            if (curChar >= numChars) {
                curChar = 0;
                try {
                    numChars = stream.read(buf);
                } catch (IOException e) {
                    throw new RuntimeException();
                }
                if (numChars <= 0)
                    return -1;
            }
            return buf[curChar++];
        }

        public int readInt() {
            int c = read();
            while (isSpaceChar(c))
                c = read();
            int sgn = 1;
            if (c == '-') {
                sgn = -1;
                c = read();
            }
            int res = 0;
            do {
                res *= 10;
                res += c - '0';
                c = read();
            } while (!isSpaceChar(c));
            return res * sgn;
        }

        public long readLong() {
            int c = read();
            while (isSpaceChar(c))
                c = read();
            int sgn = 1;
            if (c == '-') {
                sgn = -1;
                c = read();
            }
            long res = 0;
            do {
                res *= 10;
                res += c - '0';
                c = read();
            } while (!isSpaceChar(c));
            return res * sgn;
        }

        public boolean isSpaceChar(int c) {
            return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
        }

    }
}
