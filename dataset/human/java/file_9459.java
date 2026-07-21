import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.lang.reflect.Array;
import java.math.BigInteger;
import java.util.*;


public class Main {
    static int smallest = 0;
    final static long MOD = 1000000007;

    public static void main(String[] args) {
        FastScanner fs = new FastScanner();
        PrintWriter out = new PrintWriter(System.out);
       //out.println();
       int n = fs.nextInt();

       int [][] d = new int[n][2];

        for (int i = 0; i < n; i++) {
            d[i] = fs.nextIntArray(2);
        }

        boolean true_ar [] = new boolean[n];

        for (int i = 0; i < n; i++) {
            true_ar[i] = d[i][0] == d[i][1];
        }

        int len = 0;
        int maxlen = 0;
        for(int i = 0; i < n; i++) {
            if(true_ar[i]) {
                len++;
                maxlen = Math.max(len, maxlen);
            } else {
                len = 0;
            }
        }

        if(maxlen >= 3) {
            out.println("Yes");
        } else {
            out.println("No");
        }

        out.flush();
        out.close();
    }

    public static int gcd (int a, int b) {
        BigInteger aa = BigInteger.valueOf(a);
        BigInteger bb = BigInteger.valueOf(b);
        return (int)aa.gcd(bb).longValue();
    }

    public static String rString(String s) {
        return new StringBuilder(s).reverse().toString();
    }

    public static long modpow(long exp, long pow) {
        BigInteger exp_b = BigInteger.valueOf(exp);
        BigInteger pow_b = BigInteger.valueOf(pow);
        return exp_b.modPow(pow_b, BigInteger.valueOf(MOD)).longValue();
    }

    public static int powoftwo(long n){
        int count = 0;
        while(n != 0) {
            n >>= 1;
            count++;
        }
        return count - 1;
    }

    public static void rotate(int[] nums, int k) {
        int n = nums.length;
        if(k > 0) {
            for(int j = 0; j < k; j++) {
                for (int i = 0; i < n; i++) {
                    int temp = nums[(i + k) % n];
                    nums[(i + k) % n] = nums[i];
                    nums[i] = temp;
                }
            }
        }
    }


    static class FastScanner {
        BufferedReader br;
        StringTokenizer st;

        public FastScanner() {
            try {
                br = new BufferedReader(new InputStreamReader(System.in));
                // br = new BufferedReader(new FileReader("chat.txt"));
                st = new StringTokenizer("");
            } catch (Exception e) {
                e.printStackTrace();
            }
        }

        public String next() {
            if (st.hasMoreTokens())
                return st.nextToken();
            try {
                st = new StringTokenizer(br.readLine());
            } catch (Exception e) {
                e.printStackTrace();
            }
            return st.nextToken();
        }

        public int nextInt() {
            return Integer.parseInt(next());
        }

        public long nextLong() {
            return Long.parseLong(next());
        }

        public double nextDouble() {
            return Double.parseDouble(next());
        }

        public String nextLine() {
            String line = "";
            try {
                line = br.readLine();
            } catch (Exception e) {
                e.printStackTrace();
            }
            return line;
        }

        public char nextChar() {
            return next().charAt(0);
        }

        public Integer[] nextIntegerArray(int n) {
            Integer[] a = new Integer[n];
            for (int i = 0; i < n; i++)
                a[i] = nextInt();
            return a;
        }

        public int[] nextIntArray(int n) {
            int[] a = new int[n];
            for (int i = 0; i < n; i++)
                a[i] = nextInt();
            return a;
        }

        public long[] nextLongArray(int n) {
            long[] a = new long[n];
            for (int i = 0; i < n; i++)
                a[i] = nextLong();
            return a;
        }

        public char[] nextCharArray() {
            return nextLine().toCharArray();
        }
    }

}
