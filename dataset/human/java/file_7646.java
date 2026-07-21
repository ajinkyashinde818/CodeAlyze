import java.io.*;
import java.util.*;
import java.util.function.*;

final class Solver {
	static final Solver INSTANCE = new Solver();

	void solve(Supplier<String> sc) {
		int N = Integer.parseInt(sc.get());
		long K = Long.parseLong(sc.get());
		int[] A = new int[N];
		Arrays.setAll(A, $ -> Integer.parseInt(sc.get()) - 1);

		BitSet visited = new BitSet();
		int pos = 0;
		int[] path = new int[N];
		int start = -1;
		int[] circular = null;
		for (int i = 0; i < N; i++) {
			path[i] = pos;
			if (visited.get(pos)) {
				start = indexOf(path, pos);
				circular = Arrays.copyOfRange(path, start, i);
				break;
			}
			visited.set(pos);
			pos = A[pos];
		}

		if (K <= start) {
			System.out.println(path[(int) K] + 1);
		} else {
			System.out.println(circular[(int) ((K - start) % circular.length)] + 1);
		}
	}

	int indexOf(int[] array, int value){
		for (int i = 0; i < array.length; i++) {
			if (array[i] == value) return i;
		}
		return -1;
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
