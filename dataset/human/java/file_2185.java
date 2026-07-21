import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.io.PrintStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
import java.io.BufferedReader;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 *
 * @author Eric
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        FastReader in = new FastReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        DDivGame solver = new DDivGame();
        solver.solve(1, in, out);
        out.close();
    }

    static class DDivGame {
        public void solve(int testNumber, FastReader in, PrintWriter out) {
            long n = in.nextLong();
            int res = solveMe(n);
            out.println(res);

            //out.print("Case #"+ testNumber + ": ");
        }

        private int solveMe(long n) {
            int res = 0;
            boolean[] primes = findPrimes((long) (Math.sqrt(n) + 1));
            for (int i = 0; i < primes.length; i++) {
                if (!primes[i])
                    continue;
                long mul = i;
                while (n % mul == 0) {
                    res++;
                    n /= mul;
                    mul *= i;
                }
                while (n % i == 0) {
                    n /= i;
                }
            }
            if (n != 1)
                res++;
            return res;
        }

        private boolean[] findPrimes(long max) {
            boolean[] primes = new boolean[(int) max];
            for (int i = 2; i < primes.length; i++) {
                primes[i] = true;
            }
            for (int i = 2; i < primes.length; i++) {
                for (int j = 2; i * j < max; j++) {
                    primes[i * j] = false;
                }
            }
            return primes;
        }

    }

    static class FastReader {
        public BufferedReader br;
        public StringTokenizer st;
        String context = null;

        public FastReader(InputStream in) {
            this(new InputStreamReader(in));
        }

        public FastReader(InputStreamReader input) {
            br = new BufferedReader(input);
        }

        public String next() {
            if (context != null) {
                System.err.print("[" + context + "] Wait for input ...");
            }
            while (st == null || !st.hasMoreElements()) {
                try {
                    String s = br.readLine();
                    if (s == null)
                        return null;
                    st = new StringTokenizer(s);
                } catch (IOException e) {
                    e.printStackTrace();
                    throw new RuntimeException("Could not read");
                }
            }
            String res = st.nextToken();
            if (context != null) {
                System.err.println("[" + context + "] ... received : " + res);
            }
            return res;
        }

        public long nextLong() {
            return Long.parseLong(next());
        }

    }
}
