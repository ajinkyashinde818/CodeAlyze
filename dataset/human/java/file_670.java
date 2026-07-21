import java.io.*;
import java.math.*;
import java.util.*;
import java.lang.*;

public class Main implements Runnable {
    static class InputReader {
        private InputStream stream;
        private byte[] buf = new byte[1024];
        private int curChar;
        private int numChars;
        private SpaceCharFilter filter;
        private BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        public InputReader(InputStream stream) {
            this.stream = stream;
        }

        public int read() {
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

        public String nextLine() {
            String str = "";
            try {
                str = br.readLine();
            } catch (IOException e) {
                e.printStackTrace();
            }
            return str;
        }

        public int nextInt() {
            int c = read();

            while (isSpaceChar(c))
                c = read();

            int sgn = 1;

            if (c == '-') {
                sgn = -1;
                c = read();
            }

            int res = 0;
            do {
                if (c < '0' || c > '9')
                    throw new InputMismatchException();
                res *= 10;
                res += c - '0';
                c = read();
            }
            while (!isSpaceChar(c));

            return res * sgn;
        }

        public long nextLong() {
            int c = read();
            while (isSpaceChar(c))
                c = read();
            int sgn = 1;
            if (c == '-') {
                sgn = -1;
                c = read();
            }
            long res = 0;

            do {
                if (c < '0' || c > '9')
                    throw new InputMismatchException();
                res *= 10;
                res += c - '0';
                c = read();
            }
            while (!isSpaceChar(c));
            return res * sgn;
        }

        public double nextDouble() {
            int c = read();
            while (isSpaceChar(c))
                c = read();
            int sgn = 1;
            if (c == '-') {
                sgn = -1;
                c = read();
            }
            double res = 0;
            while (!isSpaceChar(c) && c != '.') {
                if (c == 'e' || c == 'E')
                    return res * Math.pow(10, nextInt());
                if (c < '0' || c > '9')
                    throw new InputMismatchException();
                res *= 10;
                res += c - '0';
                c = read();
            }
            if (c == '.') {
                c = read();
                double m = 1;
                while (!isSpaceChar(c)) {
                    if (c == 'e' || c == 'E')
                        return res * Math.pow(10, nextInt());
                    if (c < '0' || c > '9')
                        throw new InputMismatchException();
                    m /= 10;
                    res += (c - '0') * m;
                    c = read();
                }
            }
            return res * sgn;
        }

        public String readString() {
            int c = read();
            while (isSpaceChar(c))
                c = read();
            StringBuilder res = new StringBuilder();
            do {
                res.appendCodePoint(c);
                c = read();
            }
            while (!isSpaceChar(c));

            return res.toString();
        }

        public boolean isSpaceChar(int c) {
            if (filter != null)
                return filter.isSpaceChar(c);
            return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
        }

        public String next() {
            return readString();
        }

        public interface SpaceCharFilter {
            public boolean isSpaceChar(int ch);
        }
    }

    public static void main(String args[]) throws Exception {
        new Thread(null, new Main(), "Main", 1 << 26).start();
    }

    long modPow(long a, long p, long m) {
        if (a == 1) return 1;
        long ans = 1;
        while (p > 0) {
            if (p % 2 == 1) ans = (ans * a) % m;
            a = (a * a) % m;
            p >>= 1;
        }
        return ans;
    }

    long modInv(long a, long m) {
        return modPow(a, m - 2, m);
    }


    long gcd(long a,long b){
        if(b==0)return a;
        return gcd(b,a%b);
    }



    class DSU {
        int par[], size[], connectedComponent;

        DSU(int n) {
            par = new int[n];
            size = new int[n];
            for (int i = 0; i < n; i++) {
                size[i] = 1;
                par[i] = i;
            }
            connectedComponent = n;
        }

        int root(int n) {
            if (n == par[n]) return n;
            return par[n] = root(par[n]);
        }

        boolean union(int u, int v) {
            return f_union(root(u), root(v));
        }

        boolean f_union(int u, int v) {
            if (u == v) return false;
            if (size[u] > size[v]) {
                size[u] += size[v];
                par[v] = u;
            } else {
                size[v] += size[u];
                par[u] = v;
            }
            connectedComponent--;
            return true;
        }

        DSU clone_DSU() {
            DSU t = new DSU(par.length);
            t.connectedComponent = connectedComponent;
            for (int i = 0; i < par.length; i++) {
                t.par[i] = par[i];
                t.size[i] = size[i];
            }
            return t;
        }
    }

    //taken from KharYusuf
    static class LCA {
        public int[][] par;
        public int[] lvl;
        public final int LOG;
        public final int n;
        public ArrayList<Integer>[] a;

        public LCA(int n, ArrayList<Integer>[] aa) {
            a = aa;
            this.n = n;
            LOG = log2(n) + 1;
            par = new int[n][LOG];
            lvl = new int[n];
        }

        public void build(int u) {
            dfs(u, -1, 0);
            for (int j = 1; j < LOG; j++)
                for (int i = 0; i < n; i++) {
                    par[i][j] = -1;
                    if (par[i][j - 1] != -1) par[i][j] = par[par[i][j - 1]][j - 1];
                }
        }

        public void dfs(int cur, int p, int l) {
            par[cur][0] = p;
            lvl[cur] = l;
            for (int i : a[cur]) if (i != p) dfs(i, cur, l + 1);
        }

        public int query(int u, int v) {
            if (lvl[u] < lvl[v]) {
                int t = u;
                u = v;
                v = t;
            }
            int dis = lvl[u] - lvl[v];
            while (dis > 0) {
                int raise = log2(dis);
                u = par[u][raise];
                dis ^= 1 << raise;
            }
            if (u == v) return u;
            for (int i = LOG - 1; i >= 0; i--) {
                if (par[u][i] != -1 && par[u][i] != par[v][i]) {
                    u = par[u][i];
                    v = par[v][i];
                }
            }
            return par[u][0];
        }

        public int dist(int u, int v) {
            return lvl[u] + lvl[v] - (lvl[query(u, v)] << 1);
        }

        public int log2(int i) {
            int cnt = -1;
            while (i > 0) {
                i >>= 1;
                cnt++;
            }
            return cnt;
        }

    }





    PrintWriter out;
    InputReader sc;

    public void run() {
        sc = new InputReader(System.in);
        // Scanner sc=new Scanner(System.in);
        //  Random sc=new Random();
        out = new PrintWriter(System.out);

        int n=sc.nextInt();
        if(n<10){
            out.println(sc.nextInt()+100*(10-n));
        }
        else{
            out.println(sc.nextInt());
        }

        out.close();
    }


}
