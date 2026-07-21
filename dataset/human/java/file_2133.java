import java.io.*;
import java.util.*;
import java.util.function.*;

final class Solver {
	static final Solver INSTANCE = new Solver();

	void solve(Supplier<String> sc) {
		long N = Long.parseLong(sc.get());
		int result = 0;
		for (long z = 2; z * z <= N; z++){
			long n = N;
			int count = 0;
			while (n % z == 0){
				n /= z;
				count++;
			}

			for (int i = 1; count - i >= 0; i++) {
				count -= i;
				result++;
			}

			N = n;
		}
		if (N > 1) result += 1;
		System.out.println(result);
	}
}

class Main {
	public static void main(String... args) {
		System.setOut(new PrintStream(new BufferedOutputStream(System.out)));
		var reader = new BufferedReader(new InputStreamReader(System.in));
		Solver.INSTANCE.solve(new Supplier<>() {
			StringTokenizer line;

			public String get() {
				while (line == null || !line.hasMoreTokens()) try {
					line = new StringTokenizer(reader.readLine());
				} catch (IOException e) {
					throw new UncheckedIOException(e);
				}
				return line.nextToken();
			}
		});
		System.out.flush();
	}
}
