import java.util.*;
import java.io.*;
class Main {
    static long[] factrial;
    static long[] inverse;
    static long MOD;
    public static void main(String[] args) {
        FastScanner sc = new FastScanner();
        int N = sc.nextInt();
        long mod = (long)(1e9+7);
        long[] a = new long[N];
        long[] b = new long[N-1];
        for(int i = 0; i<N; i++) {
            a[i] = sc.nextLong();
        }
        for(int i = 0; i<N-1; i++) {
            b[i] = (a[i+1] - a[i])%mod;
        }
        int max = (int)(3e5);
        factrial= new long[max]; //階乗を保持
        inverse= new long[max];  //逆元を保持
        MOD = mod;
        factrial[0] = 1;
        inverse[0] = 1;
            
        for (int i = 1; i < max; i++) {
            factrial[i] = factrial[i - 1] * i;  //階乗を求める
            factrial[i]%=MOD;
            inverse[i] = pow(i, (int)MOD - 2); 
        }
    
        long kake = 0;
        long ans = 0;
        for(int i = 0; i<N-1; i++) {
            kake += inverse[i+1]%mod;
            pe((i+1)+" "+inverse[i+1]);
            kake %= mod;
            //pe(kake);
            ans += b[i]*kake%mod;
            ans %= mod;
            //pe("ans "+ans);
        }
        ans *= factrial[N-1]%mod;
	p(ans%mod);
    }
    
    public static long combine(int n, int k) {
        return factrial[n] * inverse[k] % MOD * inverse[n - k] % MOD;
    }
    
    public static long pow(long x, int n) { //x^n 計算量O(logn)
		long ans = 1;
		while (n > 0) {
			if ((n & 1) == 1) {
				ans = ans * x % MOD;
			}
			x = x * x % MOD; //一周する度にx, x^2, x^4, x^8となる
			n >>= 1; //桁をずらす n = n >> 1
		}
		return ans;
	}
    public static <T> void p(T element) {
	System.out.println(element);
    }
    public static <T> void pe(T element) {
        System.err.println(element);
        }
    public static int min(int a, int b, int c) {
	int min = Math.min(a,b);
	min = Math.min(min,c);
	return min;
    }
    public static int max(int a, int b,int c) {
	int max= Math.max(a,b);
	max = Math.max(max,c);
        return max;
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
        } else {
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
 
    private int readByte() {
        if (hasNextByte())
            return buffer[ptr++];
        else
            return -1;
    }
 
    private boolean isPrintableChar(int c) {
        return 33 <= c && c <= 126;
    }
 
    public boolean hasNext() {
        while (hasNextByte() && !isPrintableChar(buffer[ptr]))
            ptr++;
        return hasNextByte();
    }
 
    public String next() {
        if (!hasNext())
            throw new NoSuchElementException();
        StringBuilder sb = new StringBuilder();
        int b = readByte();
        while (isPrintableChar(b)) {
            sb.appendCodePoint(b);
            b = readByte();
        }
        return sb.toString();
    }
 
    public long nextLong() {
        if (!hasNext())
            throw new NoSuchElementException();
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
        while (true) {
            if ('0' <= b && b <= '9') {
                n *= 10;
                n += b - '0';
            } else if (b == -1 || !isPrintableChar(b)) {
                return minus ? -n : n;
            } else {
                throw new NumberFormatException();
            }
            b = readByte();
        }
    }
 
    public int nextInt() {
        long nl = nextLong();
        if (nl < Integer.MIN_VALUE || nl > Integer.MAX_VALUE)
            throw new NumberFormatException();
        return (int) nl;
    }
 
    public double nextDouble() {
        return Double.parseDouble(next());
    }
}
