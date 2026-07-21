import java.util.*;
import java.io.*;

public class Main {
	static int mod = (int) 1e9 + 7;
	
	public static void main(String[] args) {
		FastScanner fs = new FastScanner(System.in);
		int N = fs.nextInt(), M = fs.nextInt();
		int a[] = new int[M+1];
		for(int i=0;i<M;i++)a[i] = fs.nextInt();
		a[M]=(int)1e9;
		Arrays.sort(a);
		
		int cnt = 0;
		
		long dp[] = new long[N+1];
		dp[0] = 1;
		if(a[0]==1) {
			dp[1]=0;
			cnt++;
		}else {
			dp[1]=1;
		}
		for(int i=1;i<N;i++) {
			if(cnt<M&&a[cnt]==i+1) {
				dp[i+1]=0;
				cnt++;
			}else {
				dp[i+1] += dp[i];
				dp[i+1] %= mod;
				dp[i+1] += dp[i-1];
				dp[i+1] %= mod;
			}
		}
		System.out.println(dp[N]);
	}
}

//高速なScanner
class FastScanner {
	private BufferedReader reader = null;
	private StringTokenizer tokenizer = null;

	public FastScanner(InputStream in) {
		reader = new BufferedReader(new InputStreamReader(in));
		tokenizer = null;
	}

	public String next() {
		if (tokenizer == null || !tokenizer.hasMoreTokens()) {
			try {
				tokenizer = new StringTokenizer(reader.readLine());
			} catch (IOException e) {
				throw new RuntimeException(e);
			}
		}
		return tokenizer.nextToken();
	}

	public String nextLine() {
		if (tokenizer == null || !tokenizer.hasMoreTokens()) {
			try {
				return reader.readLine();
			} catch (IOException e) {
				throw new RuntimeException(e);
			}
		}
		return tokenizer.nextToken("\n");
	}

	public long nextLong() {
		return Long.parseLong(next());
	}

	public int nextInt() {
		return Integer.parseInt(next());
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
}
