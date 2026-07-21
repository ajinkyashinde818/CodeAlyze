import java.io.BufferedReader;
import java.io.Closeable;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.Map.Entry;
import java.util.PriorityQueue;
import java.util.StringTokenizer;
import java.util.TreeSet;

public class Main {
	
	public static class Pair implements Comparable<Pair> {
		int key;
		long value;
		
		public Pair(int key, long value) {
			this.key = key;
			this.value = value;
		}

		@Override
		public int compareTo(Pair o) {
			return -Long.compare(this.value, o.value);
		}
	}
	
	public static final int INF = Integer.MAX_VALUE / 2 - 1;
	
	public static void main(String[] args) throws IOException {
		try(final Scanner sc = new Scanner(System.in)){
			final int D = sc.nextInt();
			final int G = sc.nextInt() / 100;
			
			int[] ps = new int[D];
			int[] cs = new int[D];
			for(int i = 0; i < D; i++) {
				ps[i] = sc.nextInt();
				cs[i] = sc.nextInt() / 100;
			}
			
			int[] DP = new int[G + 1];
			Arrays.fill(DP, INF);
			
			DP[0] = 0;
			for(int i = 0; i < D; i++) {
				for(int value = DP.length - 1; value >= 0; value--) {
					if(DP[value] >= INF) { continue; }
					
					for(int cnt = 1; cnt < ps[i]; cnt++) {
						final int next = Math.min(G, value + (i + 1) * cnt);
						DP[next] = Math.min(DP[next], DP[value] + cnt);
					}
					final int comp = Math.min(G, value + (i + 1) * ps[i] + cs[i]);
					DP[comp] = Math.min(DP[comp], DP[value] + ps[i]);
				}
			}
			
			System.out.println(DP[G]);
		}
	}

	public static class Scanner implements Closeable {
		private BufferedReader br;
		private StringTokenizer tok;

		public Scanner(InputStream is) throws IOException {
			br = new BufferedReader(new InputStreamReader(is));
		}

		private void getLine() throws IOException {
			while(!hasNext()){
				tok = new StringTokenizer(br.readLine());
			}
		}

		private boolean hasNext() {
			return tok != null && tok.hasMoreTokens();
		}

		public String next() throws IOException {
			getLine();
			return tok.nextToken();
		}

		public int nextInt() throws IOException {
			return Integer.parseInt(next());
		}

		public long nextLong() throws IOException {
			return Long.parseLong(next());
		}

		public double nextDouble() throws IOException {
			return Double.parseDouble(next());
		}

		public int[] nextIntArray(int n) throws IOException {
			final int[] ret = new int[n];
			for(int i = 0; i < n; i++){
				ret[i] = this.nextInt();
			}
			return ret;
		}

		public long[] nextLongArray(int n) throws IOException {
			final long[] ret = new long[n];
			for(int i = 0; i < n; i++){
				ret[i] = this.nextLong();
			}
			return ret;
		}

		public void close() throws IOException {
			br.close();
		}
	}
}
