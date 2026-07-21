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
		solver.readB(in.readLine());
		solver.readC(in.readLine());
		// for (; solver.hasNext();) {
		// solver.readBody(in.readLine());
		// }
		solver.solve();
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
		N = Integer.parseInt(strArr[0]);
		// System.out.println(N);
		A = new int[N + 1];
		B = new int[N + 1];
		C = new int[N + 1];
	}

	public void readA(String str) {
		String[] strArr = str.split("\\s+");
		for (int i = 0; i < N; i++)
			A[i + 1] = Integer.parseInt(strArr[i]);
	}

	public void readB(String str) {
		String[] strArr = str.split("\\s+");
		for (int i = 0; i < N; i++)
			B[i + 1] = Integer.parseInt(strArr[i]);
	}

	public void readC(String str) {
		String[] strArr = str.split("\\s+");
		for (int i = 0; i < N - 1; i++)
			C[i + 1] = Integer.parseInt(strArr[i]);
	}

	int[] A;
	int[] B;
	int[] C;

	public boolean hasNext() {
		return cnt < N;
	}

	public void readBody(String str) {
		// System.out.println(str);
		cnt++;
	}

	public void solve() {
		int ans = 0;
		for (int i = 1; i <= N; i++) {
			ans += B[A[i]];
			if (i >= N)
				continue;
			if (A[i] + 1 == A[i + 1])
				ans += C[A[i]];
		}
		System.out.println(ans);
	}
}
