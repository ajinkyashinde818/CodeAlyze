import java.io.*;
import java.util.*;

public class Main {

	void submit() {
		String ss = nextToken();
		char[] s = ss.toCharArray();
		
		int n = s.length;
		
		int ptr = 0;
		
		int[] notX = new int[n];
		
		for (int i = 0; i < n; i++) {
			if (s[i] != 'x') {
				notX[ptr++] = i;
			}
		}
		
		notX = Arrays.copyOf(notX, ptr);
		
		for (int i = 0, j = ptr - 1; i < j; i++, j--) {
			if (s[notX[i]] != s[notX[j]]) {
				out.println(-1);
				return;
			}
		}
		
		if (ptr == 0) {
			out.println(0);
			return;
		}
		
		String one, two;
		if (ptr % 2 == 0) {
			one = ss.substring(0, notX[ptr / 2 - 1]);
			two = reverse(ss.substring(notX[ptr / 2] + 1));
		} else {
			one = ss.substring(0, notX[ptr / 2]);
			two = reverse(ss.substring(notX[ptr / 2] + 1));
		}
		
		out.println(go(one, two));
	}
	
	int go(String one, String two) {
		one += "z";
		two += "z";
		int ret = 0;
		List<Integer> lOne = go(one);
		List<Integer> lTwo = go(two);
		for (int i = 0; i < lOne.size(); i++) {
			ret += Math.abs(lOne.get(i) - lTwo.get(i));
		}
		return ret;
	}
	
	List<Integer> go(String s) {
		List<Integer> ret = new ArrayList<>();
		int cur = 0;
		for (int i = 0; i < s.length(); i++) {
			if (s.charAt(i) == 'x') {
				cur++;
			} else {
				ret.add(cur);
				cur = 0;
			}
		}
		return ret;
	}
	
	String reverse(String s) {
		return new StringBuilder(s).reverse().toString();
	}

	void preCalc() {

	}

	void stress() {

	}

	void test() {

	}

	Main() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		preCalc();
		submit();
		//stress();
		//test();
		out.close();
	}

	static final Random rng = new Random();

	static int rand(int l, int r) {
		return l + rng.nextInt(r - l + 1);
	}

	public static void main(String[] args) throws IOException {
		new Main();
	}

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;

	String nextToken() {
		while (st == null || !st.hasMoreTokens()) {
			try {
				st = new StringTokenizer(br.readLine());
			} catch (IOException e) {
				throw new RuntimeException(e);
			}
		}
		return st.nextToken();
	}

	String nextString() {
		try {
			return br.readLine();
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
	}

	int nextInt() {
		return Integer.parseInt(nextToken());
	}

	long nextLong() {
		return Long.parseLong(nextToken());
	}

	double nextDouble() {
		return Double.parseDouble(nextToken());
	}
}
