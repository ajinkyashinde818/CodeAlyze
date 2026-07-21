import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {
	
	public static void main(String[] args) throws IOException {
		Main mainObj = new Main();
		mainObj.solve();
	}

	public void solve() throws IOException {
		FastScanner fs = new FastScanner();
		int n = fs.nextInt();
		long k = fs.nextLong();
		
		int[] teleArr = new int[n];
		for(int i = 0 ; i < n; i++) {
			teleArr[i] = fs.nextInt() - 1;
		}
		
		int[] spaceArr = new int[n];
		
		int nowIndex = 0;
		spaceArr[0]++;
		
		ArrayList<Integer> pathList = new ArrayList<>();
		while(spaceArr[nowIndex] < 2) {
			pathList.add(nowIndex);
			int nextTown = teleArr[nowIndex];
			spaceArr[nextTown]++;
			nowIndex = nextTown;
//			System.out.println(Arrays.toString(spaceArr));
		}
		
//		System.out.println(pathList);
		
		if((long)pathList.size() >= k+1) {
			System.out.println(pathList.get((int)k)+1);
			return;
		}
		
		int loopStart = nowIndex;
		int loopStartDistance = 0;
		
		for(int i = 0; i < pathList.size(); i++) {
			if(pathList.get(i) == loopStart) {
				break;
			}
			loopStartDistance++;
		}
		
		int nonLoop = loopStartDistance;
		int loop = pathList.size() - loopStartDistance;
		
//		System.out.println(nonLoop);
//		System.out.println(loop);
		
		int destination = (int) ((k - (long)nonLoop) % (long)loop);
		System.out.println(pathList.get(destination + nonLoop)+1);
		
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
