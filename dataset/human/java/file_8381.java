import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

class Main {
	public static void main(String args[]) throws IOException {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		Solver solver = new Solver();
		solver.init();
		solver.readHead(in.readLine());
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
		N = Integer.parseInt(strArr[0]);
		// System.out.println(N);
		int a = Integer.parseInt(strArr[0]);
		int b = Integer.parseInt(strArr[1]);
		int c = 1;
		for (int i = 2; a > 1 && b > 1 && a >= i && b >= i;) {
			if (a % i == 0 && b % i == 0) {
				a /= i;
				b /= i;
				c *= i;
				// System.out.println(a + " " + b + " " + c);
			} else
				i++;
		}
		System.out.println((long) a * (long) b * (long) c);
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
