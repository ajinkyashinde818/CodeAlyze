import java.io.*;
import java.util.*;

final class Solver {
	static final Solver INSTANCE = new Solver();

	void solve(Iterator<String> sc) {
		int K = Integer.parseInt(sc.next());
		int S = Integer.parseInt(sc.next());
		int sum = 0;
		for (int x = 0; x <= K && x <= S; x++) {
			int remaining = S - x;
			sum += Math.max(Math.min(remaining, K) - Math.max(remaining - K, 0) + 1, 0);
		}
		System.out.println(sum);
	}
}

class Main {
	public static void main(String... args) {
		BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
		Solver.INSTANCE.solve(new Iterator<String>() {
			private StringTokenizer tokenizer;

			public boolean hasNext() {
				return true;
			}

			public String next() {
				if (tokenizer == null || !tokenizer.hasMoreTokens()) {
					try {
						tokenizer = new StringTokenizer(reader.readLine());
					} catch (IOException e) {
						throw new UncheckedIOException(e);
					}
				}
				return tokenizer.nextToken();
			}
		});
	}
}
