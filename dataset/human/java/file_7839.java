import java.io.BufferedReader;
import java.io.Closeable;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.math.BigDecimal;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Comparator;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Iterator;
import java.util.LinkedList;
import java.util.ListIterator;
import java.util.Map.Entry;

import java.util.PriorityQueue;
import java.util.Random;
import java.util.StringTokenizer;
import java.util.TreeMap;
import java.util.TreeSet;


public class Main {
	
	public static void main(String[] args) throws IOException {	
		try(final Scanner sc = new Scanner(System.in)){
			final int N = sc.nextInt();
			final long K = sc.nextLong();
			
			int[] as = new int[N];
			for(int i = 0; i < N; i++) {
				as[i] = sc.nextInt() - 1;
			}
			
			long[] depth = new long[N];
			Arrays.fill(depth, -1);
			
			{
				int curr_node = 0, curr_depth = 0;
				while(depth[curr_node] < 0) {
					depth[curr_node] = curr_depth++;
					curr_node = as[curr_node];
				}
				
				//System.out.println(curr_depth + " " + depth[curr_node]);				
				final long loop_length = curr_depth - depth[curr_node];
				final long start = K - depth[curr_node];
				if(start < 0) {
					int answer = 0;
					for(int i = 0; i < K; i++) {
						answer = as[answer];
					}
					
					System.out.println(answer + 1);
				}else {
					final long mod = start % loop_length;
				
					int answer = curr_node;
					for(int i = 0; i < mod; i++) {
						answer = as[answer];
					}
					
					System.out.println(answer + 1);
				}
			}
			
			
			
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
