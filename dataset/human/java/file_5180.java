import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Deque;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Iterator;
import java.util.List;
import java.util.Map;
import java.util.Queue;
import java.util.Set;
import java.util.StringTokenizer;
import java.util.TreeMap;
import java.util.function.BiConsumer;

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
			long q = in.nextLong();
			ArrayDeque<String> deq = new ArrayDeque<String>();
			deq.offer(s);
			boolean flg = true;
			for (long i = 0; i < q; i++) {
				int t = in.nextInt();
				if (t == 1) {
					flg = !flg;
				} else if (t == 2) {
					int f = in.nextInt();
					if (f == 1) {
						if (flg) {
							deq.offerFirst(in.next());
						} else {
							deq.offerLast(in.next());
						}
					} else if (f == 2) {
						if (flg) {
							deq.offerLast(in.next());
						} else {
							deq.offerFirst(in.next());
						}
					}
				}
			}
			StringBuilder sb = new StringBuilder();
			while (!deq.isEmpty()) {
				sb.append(deq.pop());
			}
			if (flg) {
				out.println(sb.toString());
			} else {
				out.println(sb.reverse().toString());
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

		public char nextChar() {
			return next().charAt(0);
		}

		public int nextInt() {
			return Integer.parseInt(next());
		}

		public double nextDouble() {
			return Double.parseDouble(next());
		}

		public long nextLong() {
			return Long.parseLong(next());
		}

	}
}
