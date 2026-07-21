//--- pD ---//
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

	// 0 1 2 3 4
	//     2 3 4

	private void run_case() {
		int n = reader.ni();
		long k = reader.nl();
		int[] arr = new int[n+1];
		for (int i=1; i<=n; i++) arr[i] = reader.ni();

		int cur = 1;
		int step = 0;
		Map<Integer, Integer> map = new HashMap<>();
		Map<Integer, Integer> map_step = new HashMap<>();

		while (!map.containsKey(cur)) {
			// out.println("step = " + step);
			map.put(cur, step);
			map_step.put(step, cur);
			cur = arr[cur];
			step ++;
			if (step == k) {
				out.println(cur);
				return;
			}
		}

		// System.out.println("step = " + step + ", cur = " + cur);
		int start = map.get(cur);
		long len = step - start;

		k -= start;
		k %= len;

		int key = (int)k;
		// out.println("len = " + len + ", k = " + k);
		int res = map_step.get(start + key);
		System.out.println(res);

		return;
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
