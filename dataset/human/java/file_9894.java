//--- pC ---//
import java.util.*;
import java.lang.*;
import java.io.*;
public class Main {
	public static void main (String[] args) throws java.lang.Exception {
		new Solution();
	}
}
class Solution {
	Reader reader;
	PrintWriter out;
	public Solution() {
		reader = new Reader();
		out = new PrintWriter(System.out);
		while (reader.hasNext()) {
			run_case();
		}
		out.flush();
	}

	int[] arr;
	int[] costs;
	int[][] books;
	int inf = Integer.MAX_VALUE;
	int res;
	int n, m, x;
	private void run_case() {
		n = reader.ni();
		m = reader.ni();
		x = reader.ni();

		arr = new int[m+5];
		Arrays.fill(arr, x);
		costs = new int[n+5];
		books = new int[n+5][m+5];

		for (int i=1; i<=n; i++) {
			costs[i] = reader.ni();
			for (int j=1; j<=m; j++) {
				books[i][j] = reader.ni();
			}
		}

		res = inf;
		dfs(1, 0);

		if (res == inf) res = -1;
		out.println(res);

		return;
	}

	private void dfs(int idx, int sum) {
		if (check()) {
			res = Math.min(res, sum);
			return;
		}
		for (int i=idx; i<=n; i++) {
			for (int j=1; j<=m; j++) arr[j] -= books[i][j];
			dfs(i+1, sum + costs[i]);
			for (int j=1; j<=m; j++) arr[j] += books[i][j];
		}
		return;
	}

	private boolean check() {
		for (int i=1; i<=m; i++) {
			if (arr[i] > 0) return false;
		}
		return true;
	}
}


class Reader {
	BufferedReader br;
	StringTokenizer st;
	public Reader(){
		try {
			br = new BufferedReader(new InputStreamReader(System.in));
			st = new StringTokenizer(br.readLine());
		} catch (Exception e) {
			e.printStackTrace();
		}
	}
	public String next() {
		if (st.hasMoreTokens()) return st.nextToken();
		try {
			st = new StringTokenizer(br.readLine());
		} catch (Exception e) {
			e.printStackTrace();
		}
		return st.nextToken();
	}
	public boolean hasNext() {
		try {
			if (!st.hasMoreTokens() && !br.ready()) return false;
			else return true;
		} catch (Exception e) {
			e.printStackTrace();
		}
		return false;
	}
	public int ni() {return Integer.parseInt(this.next());}
	public long nl() {return Long.parseLong(this.next());}
	public String ns() {return this.next();}
}
