import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    private static final int MOD = (int) Math.pow(10, 9);

    public static void main(String[] args) {
        FastReader sc = new FastReader();
        long a = sc.nextLong();
        long b = sc.nextLong();

        long g = gcd(a, b);


            System.out.println((a * b) / g);


        System.exit(0);
    }

    static private long gcd(long m, long n) {
        if (m < n) { return gcd(n, m); }
        if (m % n == 0) { return n; }
        return gcd(n, m%n);
    }

    static class FastReader {
        BufferedReader br;
        StringTokenizer st;

        public FastReader() {
            br = new BufferedReader(new InputStreamReader(System.in));
        }

        String next() {
            while (st == null || !st.hasMoreElements()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException  e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }

        int nextInt() {
            return Integer.parseInt(next());
        }

        long nextLong() {
            return Long.parseLong(next());
        }

        double nextDouble() {
            return Double.parseDouble(next());
        }

        String nextLine() {
            String str = "";
            try{
                str = br.readLine();
            } catch (IOException e) {
                e.printStackTrace();
            }
            return str;
        }
    }
}
