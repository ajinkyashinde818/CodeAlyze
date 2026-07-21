import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;

class Main {
	public static void main(String args[]) throws IOException {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		Solver solver = new Solver();
		solver.init();
		solver.readHead(in.readLine());
		for (; solver.hasNext();) {
			solver.readBody(in.readLine());
		}
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
		String[] strArr = str.split(" ");
		N = Integer.parseInt(strArr[0]);
		// System.out.println(N);
	}

	public boolean hasNext() {
		// return cnt < N;
		return cnt < 1;
	}

	public void readBody(String str) {
		// System.out.println(str);
		cnt++;
		String[] strArr = str.split(" ");
		ArrayList<Long> cards = new ArrayList<Long>();
		for (int i = 0; i < N; i++) {
			cards.add(Long.parseLong(strArr[i]));
		}
		long total = 0;
		for (long n : cards) {
			// System.out.println(n);
			total += n;
		}
		long min = Long.MAX_VALUE;
		long top = 0;
		for (int i = 0; i < cards.size() - 1; i++) {
			top += cards.get(i);
			long diff = (total - top) - top;
			if (diff < 0)
				diff *= (-1);
			// System.out.println(diff);
			if (diff < min)
				min = diff;
		}

		System.out.println(min);
	}

	public void solve() {

	}
}
