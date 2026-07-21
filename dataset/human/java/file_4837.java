import java.io.PrintStream;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) throws Exception{
		new Main(new Scanner(System.in), System.out, System.err).exec();
	}
	public final Scanner sc;
	public final PrintStream out, err;
	public Main(final Scanner sc, final PrintStream out, final PrintStream err) {
		this.sc = sc;this.out = out;this.err = err;
	}
	static public final long pair(int a, int b) {return (((long)a) << 32) + b;}
	static public final int getPair1(long v) {return (int)(v >> 32);}
	static public final int getPari2(long v) {return (int)(v & 0xFFFFFFFF);}

	static public final long quad(long a, long b, long c, long d) {
		return ((a&0xFFFF)<< 48) + ((b&0xFFFF)<< 32) + ((c&0xFFFF)<< 16) +(d&0xFFFF);}
	static public final int getQuad1(long v) {return (int)( v >> 48          );}
	static public final int getQuad2(long v) {return (int)((v >> 32) & 0xFFFF);}
	static public final int getQuad3(long v) {return (int)((v >> 16) & 0xFFFF);}
	static public final int getQuad4(long v) {return (int)( v        & 0xFFFF);}

	static public final long record(int e, int m, int i) {
		return quad(-1, e, m, i);
	}
	static public final int re(long record) {
		return getQuad2(record);
	}
	static public final int rm(long record) {
		return getQuad3(record);
	}
	static public final int ri(long record) {
		return getQuad4(record);
	}

	//------------------------------------------

	private int p;
	private int[] inv;
	private int[] fact;
	private int[] finv;
	public final int mod(long v) {
		v %= p;
		return (int)(v < 0 ? v+p : v);
	}
	public final int mul(long a, long b) {
		return mod(a*b);
	}
	public final void initFact(double limit, double p) {
		initFact((int)limit, (int)p);
	}
	public final void initFact(int limit, int p) {
		this.p = p;
		this.inv = new int[limit+1];
		this.fact = new int[limit+1];
		this.finv = new int[limit+1];
		fact[1] = finv[1] = inv[0] = inv[1] = 1;
		for(int i=2;i<=limit;i++) {
			int a = p / i;
			int b = p % i;
			inv[i]  = mul(-a, inv[b]);
			fact[i] = mul(fact[i-1], i);
			finv[i] = mul(finv[i-1], inv[i]);
		}
	}
	public final int comb(int m, int n) {
		return mul(mul(fact[m], finv[n]), finv[m-n]);
	}
	//------------------------------------------
	static long lcm (long a, long b) {
		long temp;
		long c = a;
		c *= b;
		while((temp = a%b)!=0) {
			a = b;
			b = temp;
		}
		return (long)(c/b);
	}

	//------------------------------------------


	public void exec() throws Exception{
		final long N = sc.nextLong();
		if(N%2==1) {
			out.println(0);
			return;
		}
		if(N<100) {
			out.println(N/10);
			return;
		}
		long div = 10;
		long sum = 0;
		while(N>div) {
			sum += N/div;
			div*=5;
		}
		if(N==div) {
			sum++;
		}
		out.println(sum);
		/*
		final long N = sc.nextLong();
		if(N%2==1) {
			out.println(0);
			return;
		}
		if(N<100) {
			out.println(N/10);
			return;
		}
		long n = N / 2;
		long div = 5;
		long sum = 0;
		long ord = 1;
		while(N>ord) {
			sum += n/div;
			div *=5;
			ord *=10;
		}
		if(N==ord) {
			sum++;
		}else {
			sum--;
		}
		err.println(N+","+n+","+div+","+ord);
		out.println(sum);
		*/
	}
}
