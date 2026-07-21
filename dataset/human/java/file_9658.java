import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.BufferedWriter;
import java.io.Writer;
import java.io.OutputStreamWriter;
import java.util.InputMismatchException;
import java.io.IOException;
import java.io.InputStream;

/*
 * Copyright (c) --> Arpit
 * Date Created : 19/9/2020
 * Have A Good Day !
 */

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 *
 * @author Arpit
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        FastReader in = new FastReader(inputStream);
        OutputWriter out = new OutputWriter(outputStream);
        BGoToJail solver = new BGoToJail();
        solver.solve(1, in, out);
        out.close();
    }
    
    static class BGoToJail {
        public void solve(int testNumber, FastReader r, OutputWriter out) {
            int n = r.nextInt();
            boolean flag = false;
            int[] d_x = new int[n];
            int[] d_y = new int[n];
            for (int i = 0; i < n; i++) {
                d_x[i] = r.nextInt();
                d_y[i] = r.nextInt();
            }
            for (int i = 0; i < n; i++) {
                if (d_x[i] == d_y[i] && i + 1 < n && d_x[i + 1] == d_y[i + 1] && i + 2 < n &&
                        d_x[i + 2] == d_y[i + 2]) {
                    flag = true;
                    break;
                }
            }
            out.println(flag ? "Yes" : "No");
        }
        
    }
    
    static class FastReader {
        private InputStream stream;
        private byte[] buf = new byte[1024];
        private int curChar;
        private int numChars;
        private FastReader.SpaceCharFilter filter;
        
        public FastReader(InputStream stream) {
            this.stream = stream;
        }
        
        public int read() {
            if (numChars == -1) {
                throw new InputMismatchException();
            }
            if (curChar >= numChars) {
                curChar = 0;
                try {
                    numChars = stream.read(buf);
                } catch (IOException e) {
                    throw new InputMismatchException();
                }
                if (numChars <= 0) {
                    return -1;
                }
            }
            return buf[curChar++];
        }
        
        public int nextInt() {
            int c = read();
            while (isSpaceChar(c)) {
                c = read();
            }
            int sgn = 1;
            if (c == '-') {
                sgn = -1;
                c = read();
            }
            int res = 0;
            do {
                if (c < '0' || c > '9') {
                    throw new InputMismatchException();
                }
                res *= 10;
                res += c - '0';
                c = read();
            } while (!isSpaceChar(c));
            return res * sgn;
        }
        
        public boolean isSpaceChar(int c) {
            if (filter != null) {
                return filter.isSpaceChar(c);
            }
            return isWhitespace(c);
        }
        
        public static boolean isWhitespace(int c) {
            return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
        }
        
        public interface SpaceCharFilter {
            public boolean isSpaceChar(int ch);
            
        }
        
    }
    
    static class OutputWriter {
        private final PrintWriter writer;
        
        public OutputWriter(OutputStream outputStream) {
            writer = new PrintWriter(new BufferedWriter(new OutputStreamWriter(outputStream)));
        }
        
        public OutputWriter(Writer writer) {
            this.writer = new PrintWriter(writer);
        }
        
        public void print(Object... objects) {
            for (int i = 0; i < objects.length; i++) {
                writer.print(objects[i]);
                if (i != objects.length - 1) writer.print(" ");
            }
        }
        
        public void println(Object... objects) {
            print(objects);
            writer.println();
        }
        
        public void close() {
            writer.close();
        }
        
    }
}
