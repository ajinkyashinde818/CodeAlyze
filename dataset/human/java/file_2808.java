import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.io.FilterInputStream;
import java.io.BufferedInputStream;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 *
 * @author khokharnikunj8
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        ScanReader in = new ScanReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        abc082_b solver = new abc082_b();
        solver.solve(1, in, out);
        out.close();
    }

    static class abc082_b {
        public void solve(int testNumber, ScanReader in, PrintWriter out) {
            String s = in.scanString();
            String s1 = in.scanString();
            int array[] = new int[26];
            int array1[] = new int[26];
            int min1 = Integer.MAX_VALUE;
            int max2 = Integer.MIN_VALUE;
            for (int i = 0; i < s.length(); i++) {
                array[(int) s.charAt(i) - 97]++;
                min1 = Math.min(min1, (int) s.charAt(i) - 97);
            }
            for (int i = 0; i < s1.length(); i++) {
                array1[(int) s1.charAt(i) - 97]++;
                max2 = Math.max(max2, (int) s1.charAt(i) - 97);
            }
            if (max2 > min1) out.println("Yes");
            else if (max2 < min1) out.print("No");
            else {
                if (array[min1] != array1[min1]) {
                    if (array[min1] != s.length() || s.length() > s1.length()) out.println("No");
                    else out.println("Yes");
                } else {
                    if (array[min1] == s.length() && s.length() < s1.length()) out.println("Yes");
                    else out.println("No");
                }
            }


        }

    }

    static class ScanReader {
        private byte[] buf = new byte[4 * 1024];
        private int index;
        private BufferedInputStream in;
        private int total;

        public ScanReader(InputStream inputStream) {
            in = new BufferedInputStream(inputStream);
        }

        private int scan() {
            if (index >= total) {
                index = 0;
                try {
                    total = in.read(buf);
                } catch (Exception e) {
                    e.printStackTrace();
                }
                if (total <= 0) return -1;
            }
            return buf[index++];
        }

        public String scanString() {
            int c = scan();
            if (c == -1) return null;
            while (isWhiteSpace(c)) c = scan();
            StringBuilder res = new StringBuilder();
            do {
                res.appendCodePoint(c);
                c = scan();
            } while (!isWhiteSpace(c));
            return res.toString();
        }

        private boolean isWhiteSpace(int n) {
            if (n == ' ' || n == '\n' || n == '\r' || n == '\t' || n == -1) return true;
            else return false;
        }

    }
}
