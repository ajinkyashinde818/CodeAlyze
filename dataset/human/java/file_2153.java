import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.StringTokenizer;

public class Main {
	
	public static void main(String[] args) throws IOException {
		Main mainObj = new Main();
		mainObj.solve();
	}

	public void solve() throws IOException {
		FastScanner fs = new FastScanner();
		long n = fs.nextLong();
		
		if(n == 1) {
			System.out.println(0);
			return;
		}
		
		int sqrt = (int)Math.sqrt(n)+1;
		
//		HashMap<Long, Integer> insuMap = new HashMap<>();
		
		int[] insuArr = new int[sqrt+1];
		
		for(int i = 2; i <= sqrt; i++) {
			while(n % i == 0) {
				insuArr[i]++;
				n /= i;
			}
		}
		
		long ans = 0;
		
		if(n != 1) {
			ans++;
		}
		
		for(int i = 0; i <= sqrt; i++) {
			
			if(insuArr[i] > 0) {
				int now = 1;
				while(insuArr[i] >= now) {
					ans++;
					insuArr[i] -= now;
					now++;
				}
			}
		}
		
		System.out.println(ans);
		
	}	

	public class FastScanner {

		BufferedReader reader;
		private StringTokenizer st;

		public FastScanner() {
			st = null;
			reader = new BufferedReader(new InputStreamReader(System.in));
		}

		public String next() throws IOException {
			if (st == null || !st.hasMoreElements()) {
				st = new StringTokenizer(reader.readLine());
			}
			return st.nextToken();
		}

		public String nextLine() throws IOException {
			st = null;
			String readLine = null;
			readLine = reader.readLine();
			return readLine;
		}

		public int nextInt() throws NumberFormatException, IOException {
			return Integer.parseInt(next());
		}

		public long nextLong() throws NumberFormatException, IOException {
			return Long.parseLong(next());
		}

		public int[] nextIntArr(int n) throws NumberFormatException, IOException {
			int[] retArr = new int[n];
			for (int i = 0; i < n; i++) {
				retArr[i] = nextInt();
			}
			return retArr;
		}

		public long[] nextLongArr(int n) throws NumberFormatException, IOException {
			long[] retArr = new long[n];
			for (int i = 0; i < n; i++) {
				retArr[i] = nextLong();
			}
			return retArr;
		}

		public void close() throws IOException {
			reader.close();
		}
	}


}
