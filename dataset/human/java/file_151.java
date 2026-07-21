import java.io.BufferedReader;
import java.io.Closeable;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {
	
	public static void main(String[] args) throws IOException {
		try(final Scanner sc = new Scanner(System.in)){
			final int N = sc.nextInt();
			
			long[] as = new long[N];
			long[] abs = new long[N];
			long sum = 0;
			for(int i = 0; i < N; i++) {
				as[i] = sc.nextLong();
				abs[i] = Math.abs(as[i]);
				sum += abs[i];
			}
			
			for(int i = 0; i < N - 1; i++) {
				if(as[i] < 0) { 
					as[i] *= -1; as[i + 1] *= -1;
				}else if(as[i] == 0 && as[i + 1] < 0) {
					as[i] *= -1; as[i + 1] *= -1;
				}
			}
			
			int cnt = 0;
			for(int i = 0; i < N; i++) {
				if(as[i] < 0) { cnt++; }
			}
			
			final long min = Arrays.stream(abs).min().getAsLong();
			System.out.println(sum - (cnt > 0 ? 2 * min : 0));
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
