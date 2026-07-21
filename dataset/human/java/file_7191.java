import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.HashSet;
import java.util.NoSuchElementException;
import java.util.Set;

public class Main implements Runnable {
    public static void main(String[] args) {
        new Thread(null,new Main(), "" ,Runtime.getRuntime().maxMemory()).start();
    }

    // メイン処理
    public void run() {
        FastScanner sc = new FastScanner();
        int k = sc.nextInt();
        int n = sc.nextInt();
        int[] a = new int[n];
        for(int i = 0;i < n;i++) a[i] = sc.nextInt();
        
        // iを始点としてi-1を終点とする場合とi+1を終点とする場合の距離を求めて一番小さいやつを保持すればいい？
        long ans = Long.MAX_VALUE;
        for(int i = 0;i < n;i++) {
            int terminal1, terminal2;
            int distance1 = 0, distance2 = 0;
            
            if(i == 0) {
                terminal1 = n - 1;
                distance1 = a[terminal1] - a[i];
            }
            else {
                terminal1 = i - 1;
                distance1 = a[n - 1] - a[i] + (k - a[n - 1]) + a[terminal1];
            }
            if(i == n - 1) {
                terminal2 = 0;
                distance2 = a[n - 1] - a[terminal2];
            }
            else {
                terminal2 = i + 1;
                distance2 = a[i] + (k - a[terminal2]);
            }
            
            ans = Long.min(ans, Long.min(distance1, distance2));
        }
        
        PrintWriter out =  new PrintWriter(System.out);
        out.println(ans);
        out.flush();
    }

    // 以下、ユーティリティ
    Set<long[]> primeFactorize(long n){
        // たとえnが10^18でも約数の個数は400を超えないため素因数はもっと少なくなる
        Set<long[]> ret = new HashSet<>(500);
        for(long p = 2;p * p <= n;p++) {
            if(n % p != 0) continue;
            long num = 0;
            while(n % p == 0) {
                ++num;
                n /= p;
            }
            long[] arr = {p, num};
            ret.add(arr);
        }
        if(n != 1) {
            long[] arr = {n, 1};
            ret.add(arr);
        }

        return ret;
    }

    // nの約数を求める
    Set<Long> searchDivisor(long n){
        Set<Long> ret = new HashSet<>(200);
        for(long i = 1;i * i <= n;i++) {
            if(n % i == 0) {
                ret.add(Long.valueOf(i));
                if(i * i != n) ret.add(Long.valueOf(n / i));
            }
        }

        return ret;
    }

    // 素数判定
    public static boolean isPrime(long num) {
        if (num < 2) return false;
        else if (num == 2) return true;
        else if (num % 2 == 0) return false;

        double sqrtNum = Math.sqrt(num);
        for (int i = 3; i <= sqrtNum; i += 2) {
            if (num % i == 0) return false;
        }

        return true;
    }

    long nCm(long n, long m) {
        if(n < m) return 0l;
        long c = 1l;
        m = (n - m < m ? n - m : m);
        for(long ns = n - m + 1, ms = 1;ms <= m;ns ++, ms++) {
            c *= ns;
            c /= ms;
        }
        return c;
    }

    long modnCm(long n, long m, long mod) {
        if(n < m) return 0l;
        long upper = 1l;
        long downer = 1l;
        m = (n - m < m ? n - m : m);
        for(long ns = n - m + 1, ms = 1;ms <= m;ns ++, ms++) {
            upper = upper * ns % mod;
            downer = downer * ms % mod;
        }
        return upper * modInv(downer, mod) % mod;
    }

    // mod m での a の逆元 を計算する
    long modInv(long a, long m) {
        long b = m, u = 1, v = 0;
        while(b > 0) {
            long t = a / b;
            a -= t * b;
            long tmp = a;
            a = b;
            b = tmp;
            u -= t * v;
            tmp = u;
            u = v;
            v = tmp;
        }
        u %= m;
        if (u < 0) u += m;
        return u;
    }

    long modPow(long a, long n, long mod) {
        long res = 1l;
        while(n > 0l) {
            if(n % 2l == 1l) res = res * a % mod;
            a = a * a % mod;
            n /= 2l;
        }
        return res;
    }

}

class UnionFind {
    private int[] parent;

    UnionFind(int n) {
        parent = new int[n];
        for(int i = 0;i < n;i++) parent[i] = i;
    }

    public int rootOf(int x) {
        if(parent[x] == x) return x;
        else return parent[x] = rootOf(parent[x]);
    }

    public boolean same(int x, int y) {
        return rootOf(x) == rootOf(y);
    }

    public void unite(int x, int y) {
        x = rootOf(x);
        y = rootOf(y);
        if(x == y) return;
        parent[x] = y;
        return;
    }
}

class FastScanner {
    private final InputStream in = System.in;
    private final byte[] buffer = new byte[1024];
    private int ptr = 0;
    private int buflen = 0;
    private boolean hasNextByte() {
        if (ptr < buflen) {
            return true;
        }else{
            ptr = 0;
            try {
                buflen = in.read(buffer);
            } catch (IOException e) {
                e.printStackTrace();
            }
            if (buflen <= 0) {
                return false;
            }
        }
        return true;
    }
    private int readByte() { if (hasNextByte()) return buffer[ptr++]; else return -1;}
    private static boolean isPrintableChar(int c) { return 33 <= c && c <= 126;}
    public boolean hasNext() { while(hasNextByte() && !isPrintableChar(buffer[ptr])) ptr++; return hasNextByte();}
    public String next() {
        if (!hasNext()) throw new NoSuchElementException();
        StringBuilder sb = new StringBuilder();
        int b = readByte();
        while(isPrintableChar(b)) {
            sb.appendCodePoint(b);
            b = readByte();
        }
        return sb.toString();
    }
    public long nextLong() {
        if (!hasNext()) throw new NoSuchElementException();
        long n = 0;
        boolean minus = false;
        int b = readByte();
        if (b == '-') {
            minus = true;
            b = readByte();
        }
        if (b < '0' || '9' < b) {
            throw new NumberFormatException();
        }
        while(true){
            if ('0' <= b && b <= '9') {
                n *= 10;
                n += b - '0';
            }else if(b == -1 || !isPrintableChar(b)){
                return minus ? -n : n;
            }else{
                throw new NumberFormatException();
            }
            b = readByte();
        }
    }
    public int nextInt() {
        long nl = nextLong();
        if (nl < Integer.MIN_VALUE || nl > Integer.MAX_VALUE) throw new NumberFormatException();
        return (int) nl;
    }
    public double nextDouble() { return Double.parseDouble(next());}
}
