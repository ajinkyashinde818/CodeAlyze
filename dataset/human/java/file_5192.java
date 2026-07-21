import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Collection;
import java.util.Scanner;
import java.util.Deque;
import java.util.ArrayDeque;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */
public class Main {
	public static void main(String[] args) {
		InputStream inputStream = System.in;
		OutputStream outputStream = System.out;
		Scanner in = new Scanner(inputStream);
		PrintWriter out = new PrintWriter(outputStream);
		D solver = new D();
		solver.solve(1, in, out);
		out.close();
	}

	static class D {
		public void solve(int testNumber, Scanner in, PrintWriter out) {
			Deque<String> s = new ArrayDeque<>();
			s.addLast(in.next());
			int n = in.nextInt();

			boolean reverse = false;
			for (int i = 0; i < n; i++) {
				int t = in.nextInt();

				if (t == 1) {
					reverse = !reverse;
				} else {
					int f = in.nextInt();
					String ss = in.next();
					if (f == 1 ^ reverse) {
						s.addFirst(ss);
					} else {
						s.addLast(ss);
					}
				}
			}

			StringBuilder sb = new StringBuilder();
			while (!s.isEmpty()) {
				sb.append(s.pop());
			}

			if (reverse) {
				out.println(sb.reverse());
			} else {
				out.println(sb);
			}
		}

	}
}
