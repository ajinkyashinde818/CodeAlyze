import java.util.Arrays;
import java.util.Scanner;

final class Solver {
	static final Solver INSTANCE = new Solver();

	void solve(Scanner sc) {
		String S = sc.next();
		String T = sc.next();
		char[] s = S.toCharArray();
		char[] t = T.toCharArray();
		Arrays.sort(s);
		Arrays.sort(t);
		StringBuilder bt = new StringBuilder();
		bt.append(t);
		bt.reverse();
		System.out.println(String.valueOf(s).compareTo(bt.toString()) < 0 ? "Yes" : "No");
	}
}

class Main {
	public static void main(String... args) {
		Scanner in = new Scanner(System.in);

		Solver.INSTANCE.solve(in);

		in.close();
	}
}
