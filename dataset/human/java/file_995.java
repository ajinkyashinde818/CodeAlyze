import java.io.BufferedReader;
import java.io.Closeable;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Comparator;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.Map.Entry;

import java.util.PriorityQueue;
import java.util.Queue;
import java.util.StringTokenizer;
import java.util.TreeMap;
import java.util.TreeSet;

public class Main {
	
	public static class SegmentTree{
		int n;
		long[] dat;

		public SegmentTree(int n_) {
			int n = 1;
			while(n < n_){ n *= 2; }

			this.n = n;
			dat = new long[this.n * 2 - 1];
			for(int i = 0; i < this.n * 2 - 1 ; i++){ dat[i] = Long.MIN_VALUE; }
		}

		public long calc(long fst, long snd){ return Math.max(fst, snd); }

		public void update(int k, long a){
			k += n - 1;
			dat[k] = a;
			
			while(k > 0){
				k = (k - 1) / 2;
				dat[k] = calc(dat[k * 2 + 1], dat[k * 2 + 2]);
			}
		}

		public long query(int a, int b, int k, int l, int r){
			if(r <= a || b <= l){
				return 0;
			}else if(a <= l && r <= b){
				return dat[k];
			}else {
				return calc(query(a, b, k * 2 + 1, l, (l + r) / 2), query(a, b, k * 2 + 2 , (l + r) / 2, r));
			}
		}

		public long query(int a, int b){
			return query(a, b, 0, 0, n);
		}
	}
	
	public static void main(String[] args) throws IOException {
		try(final Scanner sc = new Scanner(System.in)){
			final int N = sc.nextInt();
			final long C = sc.nextLong();
			
			long[] xs = new long[N];
			long[] vs = new long[N];
			for(int i = 0; i < N; i++) {
				xs[i] = sc.nextLong();
				vs[i] = sc.nextLong();
			}
			
			long[] left_xs = new long[N + 1];
			long[] left_vs = new long[N + 1];
			SegmentTree left_gain = new SegmentTree(N + 1);
			for(int i = 1; i <= N; i++) {
				left_xs[i] = xs[i - 1];
				left_vs[i] = vs[i - 1] + left_vs[i - 1];
			}
			for(int i = 1; i <= N; i++) {
				left_gain.update(i, left_vs[i] - left_xs[i]);
			}
			
			long[] right_xs = new long[N + 1];
			long[] right_vs = new long[N + 1];
			SegmentTree right_gain = new SegmentTree(N + 1);
			for(int i = 1; i <= N; i++) {
				right_xs[i] = C - xs[N - i];
				right_vs[i] = vs[N - i] + right_vs[i - 1];
			}
			for(int i = 1; i <= N; i++) {
				right_gain.update(i, right_vs[i] - right_xs[i]);
			}
			//System.out.println(Arrays.toString(right_gain.dat));
			
			long answer = 0;
			for(int left = 0; left <= N; left++) {
				final long fst_gain = left_gain.query(left, left + 1);
				final long back_cost = left_xs[left];
				final long snd_gain = right_gain.query(0, (N + 1) - left);
				//System.out.println(fst_gain + " " + back_cost + " " + snd_gain);
				
				answer = Math.max(answer, Math.max(fst_gain, fst_gain - back_cost + snd_gain));
			}
			for(int right = 0; right <= N; right++) {
				final long fst_gain = right_gain.query(right, right + 1);
				final long back_cost = right_xs[right];
				final long snd_gain = left_gain.query(0, (N + 1) - right);
				//System.out.println(fst_gain + " " + back_cost + " " + snd_gain);
				
				answer = Math.max(answer, Math.max(fst_gain, fst_gain - back_cost + snd_gain));
			}
			
			System.out.println(answer);
			
			/*/
			try(final PrintWriter pw = new PrintWriter(System.out)){
				pw.printf("%.8f\n", (double)(answer) / all_pairs);
			}
			//*/
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
			for(int i = 0; i < n; i++){ ret[i] = this.nextInt();}
			return ret;
		}

		public long[] nextLongArray(int n) throws IOException {
			final long[] ret = new long[n];
			for(int i = 0; i < n; i++) { ret[i] = this.nextLong();}
			return ret;
		}

		public void close() throws IOException {
			br.close();
		}
	}
}
