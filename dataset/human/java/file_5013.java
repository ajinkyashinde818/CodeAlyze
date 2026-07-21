import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

	public static void main(String[] args) throws IOException {
		Main mainObj = new Main();
		mainObj.solve();
	}

	public void solve() throws IOException {
		FastScanner fs = new FastScanner();
		String s = fs.next();
		
		int q = fs.nextInt();
		StringBuffer sbFront = new StringBuffer();
		StringBuffer sbBack = new StringBuffer();
		
		// 0そのまま, 1反転
		int nowState = 0;
		for(int i = 0; i < q; i++) {
			int sousa = fs.nextInt();
			
			if(sousa == 1) {
				nowState = (nowState + 1) % 2;
			}else {
				int f = fs.nextInt();
				String str = fs.next();
				
				if(f == 1) {
					if(nowState == 0) {
						sbFront.append(str);
					}else {
						sbBack.append(str);
					}
				}else {
					if(nowState == 0) {
						sbBack.append(str);
					}else {
						sbFront.append(str);
					}
				}
			}
		}
		
		StringBuffer sBuf = new StringBuffer(s);
		StringBuffer ans = new StringBuffer();
		if(nowState == 0) {
			ans.append(sbFront.reverse()).append(s).append(sbBack);
			System.out.println(ans.toString());
		}else {
			ans.append(sbBack.reverse()).append(sBuf.reverse()).append(sbFront);
			System.out.println(ans.toString());
		}
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
