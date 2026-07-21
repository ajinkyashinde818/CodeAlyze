import java.nio.CharBuffer;
import java.util.Scanner;

class Solver {
	static final Solver INSTANCE = new Solver();

	void solve(Scanner sc) {
		String S = sc.next();
		int Q = sc.nextInt();
		int st = 1;
		StringBuilder head = new StringBuilder();
		StringBuilder tail = new StringBuilder();
		for (int i = 0; i < Q; i++) {
			int T = sc.nextInt();
			switch (T) {
				case 1: {
					st *= -1;
					break;
				}
				case 2: {
					int F = sc.nextInt();
					int f = (F * 2 - 3) * st;
					String C = sc.next();
					switch (f) {
						case -1: {
							head.append(C);
							break;
						}
						case 1: {
							tail.append(C);
						}
					}
				}
			}
		}
		head.reverse().append(S).append(tail);
		System.out.println((st > 0 ? head : head.reverse()).toString());
	}
}

class Main {
	public static void main(String... args) {
		Scanner in = new Scanner(System.in);

		Solver.INSTANCE.solve(in);

		in.close();
	}
}
