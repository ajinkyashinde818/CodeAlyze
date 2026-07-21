import java.util.*;
import java.io.*;

public class Main {

    private final static int MOD = 998244353; // (int)1e9 + 7;
    private static final int INF = (int)1e9;

    public Main(FastScanner in, PrintWriter out) {
        String s = in.next();
        Deque<Character> dq = new ArrayDeque<>();
        for (int i = 0; i < s.length(); i++)
            dq.addLast(s.charAt(i));

        int Q = in.nextInt();
        boolean rev = false;
        for (int q = 0; q < Q; q++) {
            int t = in.nextInt();
            if (t == 1) {
                rev = !rev;
                continue;
            }
            int f = in.nextInt();
            char c = in.next().charAt(0);
            if (f == 1) {
                if (!rev)
                    dq.addFirst(c);
                else
                    dq.addLast(c);
            } else {
                if (!rev)
                    dq.addLast(c);
                else
                    dq.addFirst(c);
            }
        }
        StringBuilder res = new StringBuilder();
        while (!dq.isEmpty()) {
            if (rev) res.append(dq.removeLast());
            else res.append(dq.removeFirst());
        }
        out.println(res);

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
