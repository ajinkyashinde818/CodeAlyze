import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.math.BigDecimal;
import java.math.BigInteger;
import java.math.RoundingMode;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashSet;
import java.util.NoSuchElementException;
import java.util.Queue;
import java.util.Set;
import java.util.stream.Stream;

class Main implements Runnable {
	private final FastScanner sc;
	private final PrintWriter out;
	//private final long MOD = 1000000007;
	//private final long MOD = 998244353;
	//private final long MOD = 1000000009;
	//private final int[] d8x = {-1,0,1,1,1,0,-1,-1};
	//private final int[] d8y = {-1,-1,-1,0,1,1,1,0};
	//private final int[] d4x = {0,1,0,-1};
	//private final int[] d4y = {-1,0,1,0};
	long n;
	
	public static void main(String[] args) {
		Thread.setDefaultUncaughtExceptionHandler((t,e) -> {e.printStackTrace();System.exit(1);});
		new Thread(null, new Main(), "", Runtime.getRuntime().maxMemory()).start();
	}
 
	Main() {
		sc = new FastScanner();
		out = new PrintWriter(System.out);
	}
 
	private void init() throws Exception {
		n = sc.nextLong();
	}
 
	private void solve() throws Exception{
		ArrayList<long[]> pf = MyMath.primeFactorization(n);
		int ans = 0;
		for(long[] p : pf){
			for(int i=1;i<=p[1];i++){
				p[1]-=i;
				ans++;
			}
		}
		out.println(ans);
	}
 
	public void run() {
		int status = 0;
		try{
			init();
			sc.close();
			solve();
		} catch (Exception e) {
			status = 1;
			e.printStackTrace();
		} finally {
			sc.close();
		}
		out.flush();
		out.close();
		System.exit(status);
	}
}

class Data {
}

class MyMath{
	public static int floor(double a){
		BigDecimal ans = new BigDecimal(String.format("%.6f", a));
		return ans.setScale(0, RoundingMode.FLOOR).intValue();
	}
	public static int ceil(double a){
		BigDecimal ans = new BigDecimal(String.format("%.6f", a));
		return ans.setScale(0, RoundingMode.CEILING).intValue();
	}
	public static double NthRoot(double num,double n){
		return Math.pow(Math.E, Math.log(num)/n);
	}
	public static double log2(double x){
		if(Double.isNaN(x) || x < 0.0) return Double.NaN;
		if(x == Double.POSITIVE_INFINITY) return Double.POSITIVE_INFINITY;
		if(x == 0.0) return Double.NEGATIVE_INFINITY;
		int k = Math.getExponent(x);
		if(k < Double.MIN_EXPONENT){
			k = Math.getExponent(x * 0x1.0p52) - 52;
		}
		if(k < 0){
			k++;
		}
		double s = Math.scalb(x, -k);
		final double LOG2_E = 1.4426950408889634;
		return k + LOG2_E * Math.log(s);
	}
	public static long gcd(long a,long b){
		while(b!=0){
			long h = a;
			a = b;
			b = h%b;
		}
		return a;
	}
	public static long gcd(long... num){
		if(num.length<2) throw new IllegalArgumentException();
		if(num.length == 2) return gcd(num[0],num[1]);
		num[num.length-2] = gcd(num[num.length-2]);
		return gcd(Arrays.copyOfRange(num,0,num.length-1));
	}
	public static long modpow(long a,long b,int mod){
		if(b<1) throw new IllegalArgumentException();
		long ans = 1;
		long temp = a % mod;
		while(b>0){
			if((b&1)==1){
				ans = ans * temp % mod;
			}
			b >>= 1;
			temp = temp * temp % mod;
		}
		return ans;		
	}
	public static long rand(long min,long max){
		return (long)(Math.random()*(max-min+1))+min;
	}
	public static boolean isPrime(int n){//83ms
		if(n == 2) return true;
		if(n == 1 || (n&1) == 0) return false;
		int d = (n-1) >> 1;
		while((d&1)==0){
			d >>= 1;
		}
		for(int i=0;i<100;i++){
			int a = (int)rand(1,n-1);
			int t = d;
			int y = (int) modpow(a,t,n);
			while(t != n-1 && y != 1 && y != n - 1){
				y = y * y % n;
				t <<= 1;
			}
			if(y != n - 1 && (t&1) == 0) return false;
		}
		return true;
	}
	public static ArrayList<long[]> primeFactorization(long n){
		ArrayList<long[]> pf = new ArrayList<>();
		for(long p = 2;p * p <= n;p++){
			if(n%p == 0){
				int cnt = 1;
				n /= p;
				while(n%p == 0){
					cnt++;
					n /= p;
				}
				pf.add(new long[]{p,cnt});
			}
		}
		if(n>1) pf.add(new long[]{n,1});
		return pf;
	}
}

class COMB{
	private final int MOD;
	private final long[] fac;
	private final long[] finv;
	private final long[] inv;

	public COMB(int max,int mod){
		MOD = mod;
		fac = new long[max];
		finv = new long[max];
		inv = new long[max];
		fac[0] = fac[1] = 1;
		finv[0] = finv[1] = 1;
		inv[1] = 1;
		for(int i=2;i<max;i++){
			fac[i] = fac[i-1] * i % MOD;
			inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
			finv[i] = finv[i-1] * inv[i] % MOD;
		}
	}

	public long com(int n,int r){
		if(n < r) return 0;
		if(n < 0 || r < 0) return 0;
		return fac[n] * (finv[r] * finv[n-r] % MOD) % MOD;
	}
}

class ExIntVector {
	private int[] a;
	private int cnt;
	public ExIntVector(int max){
		a = new int[max];
		cnt = 0;
	}
	public int size(){
		return cnt;
	}
	public void add(int x){
		a[cnt++] = x;
	}
	public int get(int i){
		return a[i];
	}
	public int getLast(){
		return a[cnt-1];
	}
	public int[] toArray(){
		return a;
	}
}

class FastScanner {
	private final InputStream in = System.in;
	private final byte[] buffer = new byte[1024];
	private int ptr = 0;
	private int buflen = 0;

	private boolean read() {
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
			return true;
		}
	}

	private boolean hasNext() {
		while (read() && !isVisibleChar(buffer[ptr]))
			ptr++;
		return read();
	}

	private int getNextChar() {
		if (read()) {
			ptr++;
			return buffer[ptr - 1];
		} else {
			return -1;
		}
	}

	private static boolean isVisibleChar(int code) {
		return code >= 33 && code <= 126;
	}

	public String next() {
		if (!hasNext())
			throw new NoSuchElementException();
		StringBuilder sb = new StringBuilder();
		int b = getNextChar();
		while (isVisibleChar(b)) {
			sb.appendCodePoint(b);
			b = getNextChar();
		}
		return sb.toString();
	}

	public long nextLong() {
		if (!hasNext())
			throw new NoSuchElementException();
		long n = 0;
		boolean sign = true;
		int b = getNextChar();
		if (b == '-') {
			sign = false;
			b = getNextChar();
		}
		if (b < '0' || b > '9') {
			throw new NumberFormatException();
		}
		while (true) {
			if (b >= '0' && b <= '9') {
				n *= 10;
				n += b - '0';
			} else if (b == -1 || !isVisibleChar(b)) {
				return sign ? n : -n;
			} else {
				throw new NumberFormatException();
			}
			b = getNextChar();
		}
	}

	public int nextInt() {
		long n = nextLong();
		if (n < Integer.MIN_VALUE || n > Integer.MAX_VALUE)
			throw new NumberFormatException();
		return (int) n;
	}

	public double nextDouble() {
		return Double.parseDouble(next());
	}
	
	public char nextChar() {
		if (!hasNext())
			throw new NoSuchElementException();
		int b = getNextChar();
		while (!isVisibleChar(b)) {
			b = getNextChar();
		}
		return (char) b;
	}

	public void close() {
		try {
			in.close();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}
}

class IntQueue {
	protected int[] a;
	protected int head, tail;

	public IntQueue(int max) {
		a = new int[max];
	}

	public void offer(int x) {
		a[tail++] = x;
	}

	public int poll() {
		return a[head++];
	}

	public int peek() {
		return a[head];
	}
	
	public int size() {
		return tail - head;
	}
}
