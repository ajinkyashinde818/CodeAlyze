import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        Scanner in = new Scanner(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        DDivGame solver = new DDivGame();
        solver.solve(1, in, out);
        out.close();
    }

    static class DDivGame {
        public void solve(int testNumber, Scanner sc, PrintWriter pw) {
            ArrayList<Integer> primes = new ArrayList<>();
            boolean[] isPrime = new boolean[(int) 5e6 + 1];
            Arrays.fill(isPrime, true);
            isPrime[0] = isPrime[1] = false;
            for (int i = 2; i * i <= (int) 5e6 + 1; i++)
                if (isPrime[i])
                    for (int j = i * i; j < isPrime.length; j += i)
                        isPrime[j] = false;
            for (int i = 1; i < isPrime.length; i++)
                if (isPrime[i])
                    primes.add(i);
            long n = sc.nextLong();
            int idx = 0, p = primes.get(idx++);
            long ans = 0;
            while (1l * p * p <= n) {
                if (n % p == 0) {
                    int c = 0;
                    while (n % p == 0) {
                        c++;
                        n /= p;
                    }
                    ans += bs(c);
                }
                p = primes.get(idx++);
            }
            if (n != 1)
                ans++;
            pw.println(ans);
        }

        private long bs(int x) {
            int low = 0, high = (int) 1e4;
            while (low <= high) {
                int mid = (low + high) / 2;
                if (mid * (mid + 1) / 2 <= x) {
                    low = mid + 1;
                } else
                    high = mid - 1;
            }
            return high;
        }

    }

    static class Scanner {
        StringTokenizer st;
        BufferedReader br;

        public Scanner(FileReader r) {
            br = new BufferedReader(r);
        }

        public Scanner(InputStream s) {
            br = new BufferedReader(new InputStreamReader(s));
        }

        public String next() {
            while (st == null || !st.hasMoreTokens()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
            return st.nextToken();
        }

        public long nextLong() {
            return Long.parseLong(next());
        }

    }
}
