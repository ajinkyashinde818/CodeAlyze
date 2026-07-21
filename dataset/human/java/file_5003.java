import java.io.BufferedReader;
import java.io.Closeable;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
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
			final char[] s = sc.next().toCharArray();
			
			LinkedList<Character> list = new LinkedList<Character>();
			for(final char c : s) {
				list.addLast(c);
			}
			
			final int Q = sc.nextInt();
			boolean reverse = false;
			for(int q = 0; q < Q; q++) {
				final int ops = sc.nextInt();
				
				if(ops == 1) {
					reverse = !reverse;
				}else {
					final int pos = Math.abs((reverse ? 1 : 0) - (sc.nextInt() - 1));
					final char[] chs = sc.next().toCharArray();
					
					if(pos == 0) {
						list.addFirst(chs[0]);
					}else {
						list.addLast(chs[0]);
					}
				}
			}
			
			if(reverse) {
				for(ListIterator<Character> iter = list.listIterator(list.size()); iter.hasPrevious(); ) {
					System.out.print(iter.previous());
				}
			}else {
				for(ListIterator<Character> iter = list.listIterator(0); iter.hasNext(); ) {
					System.out.print(iter.next());
				}
			}
			System.out.println();
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
