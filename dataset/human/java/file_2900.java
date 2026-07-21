import java.io.*;
import java.util.*;

public class Main {
    void run() {
        try {
            for (String line; (line = in.readLine()) != null; ) {
                StringTokenizer tokenizer = new StringTokenizer(line);
                int[] c = new int[8];
                for (int i = 0; i < 8; i++) {
                    c[i] = Integer.parseInt(tokenizer.nextToken());
                }
                List<Integer> cap = Arrays.asList(4, 1, 4, 1, 2, 1, 2, 1);
                int minVal = Integer.MAX_VALUE;
                List<Integer> minCap = null;
                for (int i = 0; i < 8; ++i) {
                    Collections.rotate(cap, -1);
                    int s = 0;
                    for (int j = 0; j < 8; j++) {
                        if (cap.get(j) < c[j]) s += c[j] - cap.get(j);
                    }
                    if (minCap == null || minVal > s || (minVal == s && capToString(minCap) > capToString(cap))) {
                        minVal = s;
                        minCap = new ArrayList<Integer>(cap);
                    }
                }
                sysout.println(join(minCap, " "));
            }
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }

    int capToString(List<Integer> cap) {
        StringBuilder bld = new StringBuilder();
        for (int val : cap) {
            bld.append(val);
        }
        return Integer.parseInt(bld.toString());
    }

    <T> String join(Collection<T> c, String delim) {
        StringBuilder bld = new StringBuilder();
        boolean first = true;
        for (T item : c) {
            if (!first) bld.append(delim);
            first = false;
            bld.append(item);
        }
        return bld.toString();
    }

    public static void main(String[] args) {
        new Main().run();
    }

    // flush automatically iff you call `println` or `printf` or `format`.
    PrintWriter sysout = new PrintWriter(System.out, true);

    BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer buffer = new StringTokenizer("");

    String read() {
        if (!buffer.hasMoreTokens()) {
            try {
                buffer = new StringTokenizer(in.readLine());
            } catch (IOException e) {
                throw new RuntimeException(e);
            }
        }
        return buffer.nextToken();
    }

    int readInt() {
        return Integer.parseInt(read());
    }

    long readLong() {
        return Long.parseLong(read());
    }

    double readDouble() {
        return Double.parseDouble(read());
    }

    String readLine() {
        buffer = new StringTokenizer("");
        try {
            return in.readLine();
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }
}
