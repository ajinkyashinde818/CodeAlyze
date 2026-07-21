import java.util.*;
import java.io.*;
import java.nio.charset.StandardCharsets;

public class Main {
	int N;
	long K;
	int[] A;
	long mod, amari;

	public static void main(String[] args) throws IOException {
		InputStreamReader reader = new InputStreamReader(System.in, StandardCharsets.UTF_8);
		BufferedReader in = new BufferedReader(reader);
		Main ins = new Main(in);
		ins.calc();
		ins.showResult();
	}

	Main(BufferedReader in) throws IOException {
		String[] tokens = in.readLine().split(" ");
		N = Integer.parseInt(tokens[0]);
		K = Long.parseLong(tokens[1]);
		A = new int[N];
		tokens = in.readLine().split(" ");
		for (int i = 0; i < N; ++i) {
			A[i] = Integer.parseInt(tokens[i]) - 1;
		}
		init();
	}

	void init() {
		Set<Integer> check = new HashSet<>();
		int[] dist = new int[N];
		Arrays.fill(dist, 0);
		int current = 0;
		int loopLength = 0;
		int d = 0;
		while (true) {
			if (check.contains(current)) {
				loopLength = d - dist[current];
				break;
			}
			dist[current] = d;
			check.add(current);

			current = A[current];
			++d;
		}
		amari = dist[current];
		mod = loopLength;
	}

	void calc() {
		long k = K;
		if (k >= amari + mod) {
			k = (K - amari) % mod + amari;
		}
		int current = 0;
		for (long i = 0; i < k; ++i) {
			current = A[current];
		}
		System.out.println((current + 1));
	}

	void showResult() {
	}

}
