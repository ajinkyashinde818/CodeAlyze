import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.ArrayDeque;
import java.util.Arrays;
import java.util.ArrayList;
import java.util.Deque;
import java.util.InputMismatchException;
 
public class Main {
	static int lb(int[] a, int x) {
		int l = -1, r = a.length;
		while (r-l > 1) {
			int md = (l+r)/2;
			if (a[md] < x) {
				l = md;
			} else {
				r = md;
			}
		}
		return r;
	}
    public static void main(String[] args) {
        InputReader in = new InputReader(System.in);

    	int n = in.nextInt();
    	int a[] = new int[n];
    	int b[] = new int[n];
    	for (int i = 0; i < n; i++) {
    		a[i] = in.nextInt();
    	}
    	for (int i = 0; i < n; i++) {
    		b[i] = in.nextInt();
    	}

    	int ans = 0;
    	for (int lg = 28; lg >= 0; lg--) {
    		for (int i = 0; i < n; i++) {
    			a[i] %= (1<<(lg+1));
    			b[i] %= (1<<(lg+1));
    		}
    		Arrays.sort(a);
    		Arrays.sort(b);

    		int f = 0;
    		for (int i = 0; i < n; i++) {
    			int x = a[i];
    			int di = 0;
    			di += lb(b, (1<<(lg+1)) - x);
    			di += lb(b, (1<<(lg)) - x);
    			di += lb(b, (1<<(lg+1)) + (1<<(lg+1)) - x);
    			di += lb(b, (1<<(lg+1)) + (1<<(lg)) - x);
    			if (di % 2 == 1) f ^= 1;
    		}

    		if (f == 1) ans += (1<< lg);
    	}
    	System.out.println(ans);
    }


    static class InputReader {
        private InputStream stream;
        private byte[] buf = new byte[1024];
        private int curChar;
        private int numChars;
 
        public InputReader(InputStream stream) {
            this.stream = stream;
        }
 
        private int[] nextInts(int n) {
            int[] ret = new int[n];
            for (int i = 0; i < n; i++) {
                ret[i] = nextInt();
            }
            return ret;
        }
 
        private int[][] nextIntTable(int n, int m) {
            int[][] ret = new int[n][m];
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    ret[i][j] = nextInt();
                }
            }
            return ret;
        }
 
        private long[] nextLongs(int n) {
            long[] ret = new long[n];
            for (int i = 0; i < n; i++) {
                ret[i] = nextLong();
            }
            return ret;
        }
 
        private long[][] nextLongTable(int n, int m) {
            long[][] ret = new long[n][m];
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    ret[i][j] = nextLong();
                }
            }
            return ret;
        }
 
        private double[] nextDoubles(int n) {
            double[] ret = new double[n];
            for (int i = 0; i < n; i++) {
                ret[i] = nextDouble();
            }
            return ret;
        }
 
        private int next() {
            if (numChars == -1)
                throw new InputMismatchException();
            if (curChar >= numChars) {
                curChar = 0;
                try {
                    numChars = stream.read(buf);
                } catch (IOException e) {
                    throw new InputMismatchException();
                }
                if (numChars <= 0)
                    return -1;
            }
            return buf[curChar++];
        }
 
        public char nextChar() {
            int c = next();
            while (isSpaceChar(c))
                c = next();
            if ('a' <= c && c <= 'z') {
                return (char) c;
            }
            if ('A' <= c && c <= 'Z') {
                return (char) c;
            }
            throw new InputMismatchException();
        }
 
        public String nextToken() {
            int c = next();
            while (isSpaceChar(c))
                c = next();
            StringBuilder res = new StringBuilder();
            do {
                res.append((char) c);
                c = next();
            } while (!isSpaceChar(c));
            return res.toString();
        }
 
        public int nextInt() {
            int c = next();
            while (isSpaceChar(c))
                c = next();
            int sgn = 1;
            if (c == '-') {
                sgn = -1;
                c = next();
            }
            int res = 0;
            do {
                if (c < '0' || c > '9')
                    throw new InputMismatchException();
                res *= 10;
                res += c-'0';
                c = next();
            } while (!isSpaceChar(c));
            return res*sgn;
        }
 
        public long nextLong() {
            int c = next();
            while (isSpaceChar(c))
                c = next();
            long sgn = 1;
            if (c == '-') {
                sgn = -1;
                c = next();
            }
            long res = 0;
            do {
                if (c < '0' || c > '9')
                    throw new InputMismatchException();
                res *= 10;
                res += c-'0';
                c = next();
            } while (!isSpaceChar(c));
            return res*sgn;
        }
 
        public double nextDouble() {
            return Double.valueOf(nextToken());
        }
 
        public boolean isSpaceChar(int c) {
            return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
        }
 
        public interface SpaceCharFilter {
            public boolean isSpaceChar(int ch);
        }
    }
 
    static void debug(Object... o) {
        System.err.println(Arrays.deepToString(o));
    }

}
