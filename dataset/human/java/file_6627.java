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
import java.util.HashMap;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.ListIterator;
import java.util.Map.Entry;
import java.util.PriorityQueue;
import java.util.Scanner;
import java.util.StringTokenizer;
import java.util.TreeMap;
import java.util.TreeSet;

public class Main {
	
	public static int offset(int v, int offset){ return v + offset; }
	
	public static void main(String[] args) throws IOException {
		try (Scanner sc = new Scanner(System.in)) {
			final char[] ins = sc.next().toCharArray();
			final int gx = sc.nextInt();
			final int gy = sc.nextInt();
			final int size = ins.length + 1;
			
			boolean[] move_x = new boolean[2 * size + 1];
			boolean[] move_y = new boolean[2 * size + 1];
			boolean[] next_x = new boolean[move_x.length];
			boolean[] next_y = new boolean[move_y.length];
			
			move_x[offset(0, size)] = true;
			move_y[offset(0, size)] = true;
			
			int axis = 0;
			int cnt = 0;
			boolean first = true;
			for(int i = 0; i < ins.length; i++){
				if(ins[i] == 'T'){
					if(axis == 0){ // x
						Arrays.fill(next_x, false);
						for(int x = 0; x < move_x.length; x++){
							if(x + cnt < move_x.length){ next_x[x + cnt] |= move_x[x]; }
							if(!first && x - cnt >= 0){ next_x[x - cnt] |= move_x[x]; }
						}
						{
							boolean[] tmp = move_x;
							move_x = next_x;
							next_x = tmp;
						}
					}else{ // y
						Arrays.fill(next_y, false);
						for(int y = 0; y < move_y.length; y++){
							if(y + cnt < move_y.length){ next_y[y + cnt] |= move_y[y]; }
							if(!first && y - cnt >= 0){ next_y[y - cnt] |= move_y[y]; }
						}
						{
							boolean[] tmp = move_y;
							move_y = next_y;
							next_y = tmp;
						}
					}
					
					cnt = 0;
					axis = 1 - axis;
					first = false;
				}else{
					cnt++;
				}
			}
			
			if(cnt != 0){
				if(axis == 0){ // x
					Arrays.fill(next_x, false);
					for(int x = 0; x < move_x.length; x++){
						if(x + cnt < move_x.length){ next_x[x + cnt] |= move_x[x]; }
						if(!first && x - cnt >= 0){ next_x[x - cnt] |= move_x[x]; }
					}
					{
						boolean[] tmp = move_x;
						move_x = next_x;
						next_x = tmp;
					}
				}else{ // y
					Arrays.fill(next_y, false);
					for(int y = 0; y < move_y.length; y++){
						if(y + cnt < move_y.length){ next_y[y + cnt] |= move_y[y]; }
						if(!first && y - cnt >= 0){ next_y[y - cnt] |= move_y[y]; }
					}
					{
						boolean[] tmp = move_y;
						move_y = next_y;
						next_y = tmp;
					}
				}
			}
			
			//System.out.println(move_x[offset(gx, size)]);
			//System.out.println(move_y[offset(gy, size)]);
			
			System.out.println(move_x[offset(gx, size)] && move_y[offset(gy, size)] ? "Yes" : "No");
			
		}
	}

	public static class Scanner implements Closeable {
		private BufferedReader br;
		private StringTokenizer tok;

		public Scanner(InputStream is) throws IOException {
			br = new BufferedReader(new InputStreamReader(is));
		}

		private void getLine() throws IOException {
			while (!hasNext()) {
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
			for (int i = 0; i < n; i++) {
				ret[i] = this.nextInt();
			}
			return ret;
		}

		public long[] nextLongArray(int n) throws IOException {
			final long[] ret = new long[n];
			for (int i = 0; i < n; i++) {
				ret[i] = this.nextLong();
			}
			return ret;
		}

		public void close() throws IOException {
			br.close();
		}
	}
}
