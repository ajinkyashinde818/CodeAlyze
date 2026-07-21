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
			final long N = sc.nextLong(); 
			
			final int PRIMES = (int)(Math.sqrt(N)) + 1;
			
			boolean[] is_prime = new boolean[PRIMES + 1];
			Arrays.fill(is_prime, true);
			is_prime[0] = is_prime[1] = false;
			
			long X = N, answer = 0;
			for(int i = 2; i <= PRIMES; i++) {
				if(!is_prime[i]) { continue; }
				
				long count = 0;
				while(X % i == 0) {
					X /= i;
					count++;
				}
				
				for(int j = 1; j <= count; j++) {
					count -= j;
					answer++;
				}
				
				//System.out.println(i + " " + count + " " + answer);
				
				for(int j = 2 * i; j <= PRIMES; j += i) {
					is_prime[j] = false;
				}
			}
			
			if(X > PRIMES) {
				answer++;
			}
			
			System.out.println(answer);
			
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
