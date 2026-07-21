import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.UncheckedIOException;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {
	static long mod=1000000007L;
	public static void main(String[] args) {
		SC sc = new SC(System.in);
		int N=sc.nextInt();
		int M=sc.nextInt();
		long[] dp=new long[N+1];
		Arrays.fill(dp,0);
		dp[0]=1;
		int[] dan=new int[M];
		for(int i=0; i<M; i++) {
			dan[i]=sc.nextInt();
		}
		for(int i=1; i<M; i++) {
			if(dan[i]-dan[i-1]==1) {
				pl(0);
				System.exit(0);
			}
		}
		int counter=0;
		for(int i=1; i<=N; i++) {
			if(i==1) {	//2段前がない
				if(counter<M && dan[counter]==i) {
					dp[i]=0;	//踏めない
					counter++;
				}
				else {
					dp[i]=1;	//踏める
				}
			}
			else {
				if(counter<M && dan[counter]==i) {
					dp[i]=0;
					counter++;
				}
				else {
					dp[i]=dp[i-1]+dp[i-2];
					dp[i]%=mod;
				}
			}
		}
		pl(dp[N]);
	}
	static class SC {
		private BufferedReader reader = null;
		private StringTokenizer tokenizer = null;
		public SC(InputStream in) {
			reader = new BufferedReader(new InputStreamReader(in));
		}
		public String next() {
			if (tokenizer == null || !tokenizer.hasMoreTokens()) {
				try {
					tokenizer = new StringTokenizer(reader.readLine());
				} catch (IOException e) {
					throw new UncheckedIOException(e);
				}
			}
			return tokenizer.nextToken();
		}
		public int nextInt() {
			return Integer.parseInt(next());
		}
		public long nextLong() {
			return Long.parseLong(next());
		}
		public double nextDouble() {
			return Double.parseDouble(next());
		}
		public String nextLine() {
			try {
				return reader.readLine();
			} catch (IOException e) {
				throw new UncheckedIOException(e);
			}
		}
	}
	public static void pl(Object o) {
		System.out.println(o);
	}
	public static void pl() {
		System.out.println();
	}
	public static void p(Object o) {
		System.out.print(o);
	}
}
