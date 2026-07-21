import java.io.*;

import java.io.*;
import java.util.*;
import java.util.PriorityQueue;

public class Main {
	public static long gcd(long n, long m){ if(m > n) return gcd(m,n); if(m == 0) return n; return gcd(m, n%m);}
	public static long lcm(long m, long n){ return (m/gcd(m,n))*n;}
	static int mod = 1000000007;
	static int INF = Integer.MAX_VALUE;
	static int[] dx = {0,0,1,-1};
	static int[] dy = {1,-1,0,0};
	static int[] dx8 = {0,0,1,-1,1,1,-1,-1};
	static int[] dy8 = {1,-1,0,0,1,-1,-1,1};
	public static void main(String[] args){
		FastScanner scanner = new FastScanner();
		int n = scanner.nextInt();
		int m = scanner.nextInt();
		int x = scanner.nextInt();
		int[] c = new int[n];
		int[][] a = new int[n][m];
		for(int i = 0; i < n; i++){
			c[i] = scanner.nextInt();
			for(int j = 0; j < m; j++){
				a[i][j] = scanner.nextInt();
			}
		}
		int ans = INF;
		for(int bit = 0; bit < (1<<n); bit++){
			int[] sum = new int[m];
			int cost = 0;
			for(int i = 0; i < n; i++){
				if(((bit>>i)&1) == 1){
					cost += c[i];
					for(int j = 0; j < m; j++){
						sum[j] += a[i][j];
					}
				}
			}
			boolean ok = true;
			for(int i = 0; i < m; i++){
				if(sum[i] < x){
					ok = false;
				}
			}
			if(ok){
				ans = Math.min(ans,cost);
			}
			//System.out.println(cost);
		}
		if(ans == INF){
			System.out.println(-1);
		}else{
			System.out.println(ans);
		}
	}
	public static final int lowerBound(final int[] arr, final int value) {
		 int low = 0;
		 int high = arr.length;
		 int mid;
		 while (low < high){
				 mid = ((high - low) >>> 1) + low;    //(low + high) / 2 (オーバーフロー対策)
				 if (arr[mid] < value) {
					 low = mid + 1;
				 } else {
					 high = mid;
				 }
		 }
		 return low;
	 }
	public static int upperBound(int[] array, int value) {
			 int low = 0;
			 int high = array.length;
			 int mid;
			 while( low < high ) {
					 mid = ((high - low) >>> 1) + low; // (high + low) / 2
					 if( array[mid] <= value ) {
							 low = mid + 1;
					 } else {
							 high = mid;
					 }
			 }
			 return low;
	 }
	public static boolean isPrime(int n){
		if(n == 1) return false;
		if(n == 2 || n == 3) return true;
		for(int i = 2; i <= Math.sqrt(n); i++){
			if(n % i == 0) return false;
		}
		return true;
	}
	public static char i2c(int i){
		if(0 <= i && i < 26){
			return (char)(i + 'a');
		}else{
			return (char)(i + 'A' - 26);
		}
	}
	static class Point{
		int x; int y;
		Point(int x, int y){
			this.x = x;
			this.y = y;
		}
	}
	static class Edge{
		int to;
		Edge(int to){
			this.to = to;
		}
	}
	static class Edge2 implements Comparable<Edge2>{
		int from;
		int to;
		int cost;
		Edge2(int from, int to, int cost){
			this.from = from;
			this.to = to;
			this.cost = cost;
		}
		public int compareTo(Edge2 e){
			return cost-e.cost;
		}
	}

	static class RMQ {
		private int size_, dat[];
		private int query_(int a, int b, int k, int l, int r) {
			if(r <= a || b <= l) return 2147483647;
			if(a <= l && r <= b) return dat[k];
			int lc = query_(a, b, 2 * k, l, (l + r) / 2);
			int rc = query_(a, b, 2 * k + 1, (l + r) / 2, r);
			return Math.min(lc, rc);
		}
		RMQ(int s) {
			for(size_ = 1; size_ < s;) size_ *= 2;
			dat = new int[size_ * 2];
			for(int i = 0; i < size_ * 2; i++) dat[i] = 2147483647;
		}
		public void update(int pos, int x) {
			pos += size_; dat[pos] = x;
			while(pos > 1) {
				pos /= 2;
				dat[pos] = Math.min(dat[2 * pos], dat[2 * pos + 1]);
			}
		}
		public int query(int l, int r) {
			return query_(l, r, 1, 0, size_);
		}
	}
	static int size = 2100000;
	static long[] fac = new long[size];
	static long[] finv = new long[size];
	static long[] inv = new long[size];
	//繰り返し二乗法
	public static long pow(long x, long n){
		long ans = 1;
		while(n > 0){
			if((n & 1) == 1){
				ans = ans * x;
				ans %= mod;
			}
			x = x * x % mod;
			n >>= 1;
		}
		return ans;
	}
	public static long div(long x, long y){
		return (x*pow(y, mod-2))%mod;
	}
	//fac, inv, finvテーブルの初期化、これ使う場合はinitComb()で初期化必要
	public static  void initComb(){
		fac[0] = finv[0] = inv[0] = fac[1] = finv[1] = inv[1] = 1;
		for (int i = 2; i < size; ++i) {
			fac[i] = fac[i - 1] * i % mod;
			inv[i] = mod - (mod / i) * inv[(int) (mod % i)] % mod;
			finv[i] = finv[i - 1] * inv[i] % mod;
		}
	}
	//nCk % mod
	public static long comb(int n, int k){
		return fac[n] * finv[k] % mod * finv[n - k] % mod;
	}
	//n! % mod
	public static long fact(int n){
		return fac[n];
	}
	//(n!)^-1 with % mod
	public static long finv(int n){
		return finv[n];
	}
	private static class FastScanner {
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
}
