import java.io.*;
import java.util.*;

public class Main {

	void submit() {
		String s = nextToken();

		int x0 = 0, y0 = 0, x1 = 0, y1 = 0;

		boolean noT = true;
		boolean goX = true;
		int streak = 0;

		List<Integer> lx = new ArrayList<>();
		List<Integer> ly = new ArrayList<>();

		int decX = 0;

		s += "T";

		for (char c : s.toCharArray()) {
			if (c == 'F') {
				streak++;
			} else {
				if (streak != 0) {
					if (noT) {
						decX = streak;
					} else if (goX) {
						lx.add(streak);
					} else {
						ly.add(streak);
					}
				}

				streak = 0;
				goX = !goX;
				noT = false;
			}
		}

		int toX = nextInt();
		int toY = nextInt();

		toX -= decX;

		out.println(can(toX, lx) && can(toY, ly) ? "Yes" : "No");
	}

	boolean can(int goal, List<Integer> delta) {
		// System.err.println(goal + " " + delta);
		HashSet<Integer> can = new HashSet<>();
		can.add(0);
		for (int l : delta) {
			HashSet<Integer> nxt = new HashSet<>();
			for (int was : can) {
				nxt.add(was - l);
				nxt.add(was + l);
			}
			can = nxt;
		}
		return can.contains(goal);
	}

	void preCalc() {

	}

	void stress() {

	}

	void test() {

	}

	Main() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		preCalc();
		submit();
		// stress();
		// test();
		out.close();
	}

	static final Random rng = new Random();

	static int rand(int l, int r) {
		return l + rng.nextInt(r - l + 1);
	}

	public static void main(String[] args) throws IOException {
		new Main();
	}

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;

	String nextToken() {
		while (st == null || !st.hasMoreTokens()) {
			try {
				st = new StringTokenizer(br.readLine());
			} catch (IOException e) {
				throw new RuntimeException(e);
			}
		}
		return st.nextToken();
	}

	String nextString() {
		try {
			return br.readLine();
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
	}

	int nextInt() {
		return Integer.parseInt(nextToken());
	}

	long nextLong() {
		return Long.parseLong(nextToken());
	}

	double nextDouble() {
		return Double.parseDouble(nextToken());
	}
}
