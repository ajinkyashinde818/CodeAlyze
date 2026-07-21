import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class Main {
	
	static int inf = 1_000_000_007;
	Book[] bookArr;
	int x;
	int m;
	int n;

	public static void main(String[] args) throws IOException {
		Main mainObj = new Main();
		mainObj.solve();
	}

	public void solve() throws IOException {
		FastScanner fs = new FastScanner();
		
		n = fs.nextInt();
		m = fs.nextInt();
		x = fs.nextInt();
		
		bookArr = new Book[n];
		
		for(int i = 0; i < n; i++) {
			bookArr[i] = new Book(fs.nextInt(), m);
			Book ith = bookArr[i];
			for(int j = 0; j < m; j++) {
				ith.a[j] = fs.nextInt();
			}
		}
		
		int minPrice = inf;
		for(int i = 1; i <= n; i++) {
			for(int j = 0; j < n; j++) {
				int[] indexArr = new int[i];
				minPrice = Math.min(dfs(0, indexArr, i, j-1), minPrice);
			}
		}
		
		if(minPrice == inf) {
			System.out.println(-1);
		}else {
			System.out.println(minPrice);
		}
		
	}
	
	class Book{
		int price;
		int[] a;
		
		Book(int price, int m){
			this.price = price;
			this.a = new int[m];
		}
	}

	boolean checkUnderstand(List<Book> bookArr) {
		int[] a = new int[m];
		for(Book book : bookArr) {
			for(int i = 0; i < m; i++) {
				a[i] += book.a[i];
			}
		}
		
		for(int i = 0; i < m; i++) {
			if(a[i] < x) {
				return false;
			}
		}
		return true;
	}
	
	
	int dfs(int depth, int[] indexArr, int stop, int nowIndex) {
		if(depth == stop) {
			List<Book> bookList = new ArrayList<>();
			
			int sumPrice = 0;
			
			for(int i = 0; i < stop; i++) {
				Book book = bookArr[indexArr[i]];
				bookList.add(book);
				sumPrice += book.price;
			}
			
			if(checkUnderstand(bookList)) {
				return sumPrice;
			}else {
				return inf;
			}
		}
		
		if(nowIndex >= n-1) {
			return inf;
		}
		
		int minPrice = inf;
		
		for(int i = nowIndex+1; i < n; i++) {
			indexArr[depth] = i;
			minPrice = Math.min(minPrice, dfs(depth+1, indexArr, stop, i));
		}
		
		return minPrice;
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
