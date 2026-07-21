import java.io.*;
import java.util.*;

import static java.lang.Math.*;

public class Main {
    class Reader {
        BufferedReader in;

        Reader() throws IOException {
            in = new BufferedReader(new InputStreamReader(System.in));
        }

        Reader(String name) throws IOException {
            in = new BufferedReader(new FileReader(name));
        }

        StringTokenizer tokin = new StringTokenizer("");

        String next() throws IOException {
            if (!tokin.hasMoreTokens()) {
                tokin = new StringTokenizer(in.readLine());
            }
            return tokin.nextToken();
        }

        int nextInt() throws IOException {
            return Integer.parseInt(next());
        }

        boolean hasNext() throws IOException {
            if (tokin.hasMoreTokens()) {
                return true;
            } else {
                String s = in.readLine();
                while (s != null && s.length() == 0) {
                    s = in.readLine();
                }
                if (s == null) {
                    return false;
                } else {
                    tokin = new StringTokenizer(s);
                    return true;
                }
            }
        }
    }

    class Writer {
        PrintWriter cout;

        Writer() throws IOException {
            cout = new PrintWriter(System.out);
        }

        Writer(String name) throws IOException {
            cout = new PrintWriter(new FileWriter(name));
        }

        StringBuilder out = new StringBuilder();

        void print(Object a) {
            out.append(a);
        }

        void close() {
            cout.print(out.toString());
            cout.close();
        }
    }

    void run() throws Exception {
        Reader in = new Reader();
        Writer out = new Writer();
        int n = in.nextInt();
        int d = 0;
        boolean dd[] = new boolean[3];
        for (int i = 0; i < 3; i++) {
            if (in.nextInt() == in.nextInt()) {
                d++;
                dd[i] = true;
            }
        }
        boolean must = false;
        if (d == 3) {
            must = true;
        }
        for (int i = 0; i < n - 3; i++) {
            if (dd[i % 3] == true) {
                d--;
                dd[i % 3] = false;
            }
            if (in.nextInt() == in.nextInt()) {
                d++;
                dd[i % 3] = true;
            }
            if (d == 3) {
                must = true;
            }
        }
        if (must) {
            out.print("Yes");
        } else {
            out.print("No");
        }
        out.close();
    }

    public static void main(String[] args) throws Exception {
        new Main().run();
    }
}
