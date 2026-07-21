import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;
import java.util.StringTokenizer;

/**
 * Built using CHelper plug-in Actual solution is at the top
 */

public class Main {
	public static void main(String[] args) {
		InputStream inputStream = System.in;
		OutputStream outputStream = System.out;
		InputReader in = new InputReader(inputStream);
		PrintWriter out = new PrintWriter(outputStream);
		Task solver = new Task();
		solver.solve(1, in, out);
		out.close();
	}

	static class Task {
		public void solve(int testNumber, InputReader in, PrintWriter out) {
			String s = in.next();
			String t = in.next();
			List<Character> sc = new ArrayList<>();
			List<Character> tc = new ArrayList<>();
			for(int i = 0; i < s.length(); i++) {
				sc.add(s.charAt(i));
			}
			for(int i = 0; i < t.length(); i++) {
				tc.add(t.charAt(i));
			}
			
			Collections.sort(sc);
			Collections.sort(tc, Comparator.reverseOrder());
			
			String s_ = "";
			String t_ = "";
			
			for(int i = 0; i < s.length(); i++) {
				s_ += sc.get(i);
			}
			for(int i = 0; i < t.length(); i++) {
				t_ += tc.get(i);
			}
			if(s_.compareTo(t_) < 0) {
				out.println("Yes");
			}else {
				out.println("No");
			}
		}
	}
	
	static class InputReader {
		public BufferedReader reader;
		public StringTokenizer tokenizer;

		public InputReader(InputStream stream) {
			reader = new BufferedReader(new InputStreamReader(stream), 32768);
			tokenizer = null;
		}

		public String next() {
			while (tokenizer == null || !tokenizer.hasMoreTokens()) {
				try {
					tokenizer = new StringTokenizer(reader.readLine());
				} catch (IOException e) {
					throw new RuntimeException(e);
				}
			}
			return tokenizer.nextToken();
		}

		public int nextInt() {
			return Integer.parseInt(next());
		}

	}
}
