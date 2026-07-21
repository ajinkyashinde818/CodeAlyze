import java.util.*;
import java.io.*;
import static java.lang.Math.*;

public class Main {

    private static final int MOD = (int)1e9 + 7; //998244353;
    private static final long INF = (long)1e15;

    //private StringBuilder S;
    private char[] S;
    private int[][] memo;

    public Main(FastScanner in, PrintWriter out) {
        S = in.next().toCharArray();
        int n = S.length;

        int[][] dp = new int[n + 1][2];
        // pay entire amount with one more note
        // example. S=874. We pay with 1xxx.
      	// 0th digit has one carray from 1st digit, which is 8.
        dp[0][1] = 1;
        for (int i = 1; i <= n; i++) {
            int v = S[i - 1] - '0';
          	// current digit i does not have carry over from digit i + 1
            dp[i][0] = Math.min(dp[i - 1][0] + v, dp[i - 1][1] + 10 - v);
          	// current digit has carray over from digit i + 1
          	// if v == 9, previous digit must have a carry from current digit
            if (v == 9)
                dp[i][1] = dp[i - 1][1];
            else
                dp[i][1] = Math.min(dp[i - 1][0] + v + 1, dp[i - 1][1] + 10 - v - 1);
        }
        out.println(dp[n][0]);
    }

    public Main(FastScanner in, PrintWriter out, int x) {
        //S = new StringBuilder(in.next());
        //S.reverse();
        S = in.next().toCharArray();
        int n = S.length;
        for (int i = 0, j = n - 1; i < j; i++, j--) {
            char c = S[i];
            S[i] = S[j];
            S[j] = c;
        }
        memo = new int[n][];
        for (int i = 0; i < n; i++)
            memo[i] = new int[]{-1, -1};

        out.println(go(0, 0));
    }

    // simulate subtraction; carry is either 0 or 1
    // process digit idx, the current carray value is 'carry'
    private int go(int idx, int carry) {
        if (idx == S.length)
            return carry;
        if (memo[idx][carry] >= 0) return memo[idx][carry];
        //System.out.printf("%d%n", idx);
        int v = S[idx] - '0' + carry;
        int res = (int)1e9;
        // two options:
        // 1. Pay the exact amount, no more carry for the current digit
        // 2. Use one more higher value note.
        // For example, carry = 1, digit = 7, we can either use 8 `1` note to
        // pay for it (exact amount); or we can use 1 `10` note to pay for it
        // (caused a carry 1 to the next digit).
        if (v < 10) 
            res = go(idx + 1, 0) + v;
        res = Math.min(res, go(idx + 1, 1) + 10 - v);
        memo[idx][carry] = res;
        return res;
    }

    private int gcd(int a, int b) {
        while (true) {
            if (b == 0) return a;
            int tmp = a;
            a = b;
            b = tmp % b;
        }
    }

    private long powm(long x, long p) {
        long res = 1;
        while (p > 0) {
            if (p % 2 == 1)
                res = res * x % MOD;
            x = x * x % MOD;
            p /= 2;
        }
        return res;
    }

    public static void main(String[] args) {
        PrintWriter out = new PrintWriter(System.out);
        // Scanner in = new Scanner(
                // new BufferedReader(new InputStreamReader(System.in)));
        FastScanner in = new FastScanner(System.in);

        Main sol = new Main(in, out);
        out.close();
    }
}

// Pair
class Pair<T extends Comparable<? super T>, U extends Comparable<? super U>> implements Comparable<Pair<T, U>> {
    T a;
    U b;
    Pair() { }
    Pair(T a, U b) {
        this.a = a;
        this.b = b;
    }

    @Override
    public String toString() { return "("+a.toString()+", "+b.toString()+")"; }

    @Override
    public int hashCode() { return Objects.hash(a, b); }

    @Override
    public boolean equals(Object obj) {
        if(this == obj) return true;
        if(obj == null) return false;
        if(this.getClass() != obj.getClass()) return false;
        Pair that = (Pair) obj;
        if(this.a.getClass() != that.a.getClass()) return false;
        if(this.b.getClass() != that.b.getClass()) return false;
        if(!this.a.equals(that.a)) return false;
        if(!this.b.equals(that.b)) return false;
        return true;
    }

    @Override
    public int compareTo(Pair<T, U> that) {
        int c = (this.a).compareTo(that.a);
        if(c == 0) c = (this.b).compareTo(that.b);
        return c;
    }
}


class FastScanner{
    private InputStream stream;
    private byte[] buf = new byte[1024];
    private int curChar;
    private int numChars;

    public FastScanner(InputStream stream)
    {
        this.stream = stream;
    }

    int read()
    {
        if (numChars == -1)
            throw new InputMismatchException();
        if (curChar >= numChars){
            curChar = 0;
            try{
                numChars = stream.read(buf);
            } catch (IOException e) {
                throw new InputMismatchException();
            }
            if (numChars <= 0)
                return -1;
        }
        return buf[curChar++];
    }

    boolean isSpaceChar(int c)
    {
        return c==' '||c=='\n'||c=='\r'||c=='\t'||c==-1;
    }

    boolean isEndline(int c)
    {
        return c=='\n'||c=='\r'||c==-1;
    }

    int nextInt()
    {
        return Integer.parseInt(next());
    }

    long nextLong()
    {
        return Long.parseLong(next());
    }

    double nextDouble()
    {
        return Double.parseDouble(next());
    }

    String next(){
        int c = read();
        while (isSpaceChar(c))
            c = read();
        StringBuilder res = new StringBuilder();
        do{
            res.appendCodePoint(c);
            c = read();
        }while(!isSpaceChar(c));
        return res.toString();
    }

    String nextLine(){
        int c = read();
        while (isEndline(c))
            c = read();
        StringBuilder res = new StringBuilder();
        do{
            res.appendCodePoint(c);
            c = read();
        }while(!isEndline(c));
        return res.toString();
    }
}
