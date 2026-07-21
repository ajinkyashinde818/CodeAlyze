import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

class Main {
	public static void main(String args[]) throws IOException {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		Solver solver = new Solver();
		solver.init();
		solver.readHead(in.readLine());
		solver.readA(in.readLine());
		// for (; solver.hasNext();) {
		// solver.readBody(in.readLine());
		// }
		// solver.solve();
	}
}

class Solver {
	int N;
	int cnt;

	public void init() {
		N = 0;
		cnt = 0;
	}

	public void readHead(String str) {
		String[] strArr = str.split("\\s+");
		K = Integer.parseInt(strArr[0]);
		N = Integer.parseInt(strArr[1]);
		// System.out.println(N);
	}

	int K;

	public void readA(String str) {
		String[] strArr = str.split("\\s+");
		int[] A = new int[N + 1];
		for (int i = 1; i <= N; i++) {
			A[i] = Integer.parseInt(strArr[i - 1]);
		}
		A[0] = A[N] - K;
		int dMax = A[1] - A[0];
		int start = 1;
		for (int i = 1; i <= N; i++) {
			if (A[i] - A[i - 1] > dMax) {
				dMax = A[i] - A[i - 1];
				start = i;
			}
		}
		System.out.println(K - dMax);
	}

	public boolean hasNext() {
		return cnt < N;
	}

	public void readBody(String str) {
		// System.out.println(str);
		cnt++;
	}

	public void solve() {

	}
}
