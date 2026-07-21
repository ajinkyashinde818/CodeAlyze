import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.*;

public class Main {
	static final long MOD=1000000007;//998244353;
	static long ans;
	public static void main(String[] args) {
		PrintWriter out = new PrintWriter(System.out);
		InputReader sc=new InputReader(System.in);
		int N=sc.nextInt();
		long[] X=sc.nextLongArray(N);
		long[] sum=new long[N+1];
		for (int i = 1; i < sum.length; i++) {
			sum[i]=sum[i-1]+X[i-1];
			sum[i]%=MOD;
		}
		long ans=0;
		Binomial binomial=new Binomial();
		for (int k = 1; k < N-1; k++) {
			long c=(sum[N-1]-sum[k]+MOD)%MOD;
			c=(c-sum[N-k-1]+MOD)%MOD;
			c*=modInv(k+1);
			c%=MOD;
			c*=modInv(k);
			c%=MOD;
			ans+=c;
			ans%=MOD;
		}
		for (int i = 0; i < N-1; i++) {
			long c=1;
			c*=modInv(N-1-i);
			c%=MOD;
			c*=(X[N-1]-X[i]);
			c%=MOD;
			ans+=c;
			ans%=MOD;
		}
		System.out.println((ans*binomial.p(N-1))%MOD);
 	}
	static long modPow(long x, long y) {
        long z = 1;
        while (y > 0) {
            if (y % 2 == 0) {
                x = (x * x) % MOD;
                y /= 2;
            } else {
                z = (z * x) % MOD;
                y--;
            }
        }
        return z;
    }//xのy乗mod
 
    static long modInv(long x) {
        return modPow(x, MOD - 2);
    }
	static class Binomial{
		int MAX = 510000;//ほしいサイズ
		long[] fac=new long[MAX];
		long[] finv=new long[MAX];
		long[] inv=new long[MAX];
		public Binomial(){
			fac[0] = fac[1] = 1;
		    finv[0] = finv[1] = 1;
		    inv[1] = 1;
		    for (int i = 2; i < MAX; i++){
		        fac[i] = fac[i - 1] * i % MOD;
		        inv[i] = MOD - inv[(int) (MOD%i)] * (MOD / i) % MOD;
		        finv[i] = finv[i - 1] * inv[i] % MOD;
		    }//facがx!、finvがx!の逆元,10^7くらいまでのテーブル(MAXまで)
		}
		long pinv(int k) {
			return finv[k];
		}
		long p(int k) {
			return fac[k];
		}
		long nCk(int n,int k,long MOD) {
		    if (n < k) return 0;
		    if (n < 0 || k < 0) return 0;
		    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
		}
	}
	static class InputReader { 
		private InputStream in;
		private byte[] buffer = new byte[1024];
		private int curbuf;
		private int lenbuf;
		public InputReader(InputStream in) {
			this.in = in;
			this.curbuf = this.lenbuf = 0;
		}
 
		public boolean hasNextByte() {
			if (curbuf >= lenbuf) {
				curbuf = 0;
				try {
					lenbuf = in.read(buffer);
				} catch (IOException e) {
					throw new InputMismatchException();
				}
				if (lenbuf <= 0)
					return false;
			}
			return true;
		}
 
		private int readByte() {
			if (hasNextByte())
				return buffer[curbuf++];
			else
				return -1;
		}
 
		private boolean isSpaceChar(int c) {
			return !(c >= 33 && c <= 126);
		}
 
		private void skip() {
			while (hasNextByte() && isSpaceChar(buffer[curbuf]))
				curbuf++;
		}
 
		public boolean hasNext() {
			skip();
			return hasNextByte();
		}
 
		public String next() {
			if (!hasNext())
				throw new NoSuchElementException();
			StringBuilder sb = new StringBuilder();
			int b = readByte();
			while (!isSpaceChar(b)) {
				sb.appendCodePoint(b);
				b = readByte();
			}
			return sb.toString();
		}
 
		public int nextInt() {
			if (!hasNext())
				throw new NoSuchElementException();
			int c = readByte();
			while (isSpaceChar(c))
				c = readByte();
			boolean minus = false;
			if (c == '-') {
				minus = true;
				c = readByte();
			}
			int res = 0;
			do {
				if (c < '0' || c > '9')
					throw new InputMismatchException();
				res = res * 10 + c - '0';
				c = readByte();
			} while (!isSpaceChar(c));
			return (minus) ? -res : res;
		}
 
		public long nextLong() {
			if (!hasNext())
				throw new NoSuchElementException();
			int c = readByte();
			while (isSpaceChar(c))
				c = readByte();
			boolean minus = false;
			if (c == '-') {
				minus = true;
				c = readByte();
			}
			long res = 0;
			do {
				if (c < '0' || c > '9')
					throw new InputMismatchException();
				res = res * 10 + c - '0';
				c = readByte();
			} while (!isSpaceChar(c));
			return (minus) ? -res : res;
		}
 
		public double nextDouble() {
			return Double.parseDouble(next());
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
 
		public char[][] nextCharMap(int n, int m) {
			char[][] map = new char[n][m];
			for (int i = 0; i < n; i++)
				map[i] = next().toCharArray();
			return map;
		}
	}
	}
