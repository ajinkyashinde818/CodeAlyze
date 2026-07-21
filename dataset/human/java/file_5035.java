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
	int mod = (int)1e9+7;
	Reader reader;
	public Solution () {
		reader = new Reader();
		while (reader.hasNext()) {
			run_case();
		}
	}

	private void run_case() {
		List<StringBuilder> sb = new ArrayList<>();
		sb.add(new StringBuilder());
		sb.add(new StringBuilder());
		// StringBuilder sb_e = new StringBuilder();
		int dir = 0;

		String str = reader.ns();
		int q_num = reader.ni();
		for (;q_num-->0;) {
			int q = reader.ni();
			if (q == 1) {
				dir = (dir + 1) % 2;
			} else {
				q = reader.ni();
				char c = reader.ns().charAt(0);
				if (q == 1) { // add f
					sb.get(dir).append(c);
				} else {
					int t = (dir + 1) % 2;
					sb.get(t).append(c);
				}
			}
		}

		String res = "";
		if (dir == 0) {
			String str_f = sb.get(0).reverse().toString();
			String str_e = sb.get(1).toString();
			res = str_f + str + str_e;
		} else {
			String str_f = sb.get(1).reverse().toString();
			String str_e = sb.get(0).toString();
			res = str_f + new StringBuilder(str).reverse().toString() + str_e;
		}

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
	public String ns() {return this.next();}
}
