import java.io.InputStream;
import java.io.PrintStream;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {
	InputStream in = System.in;
	PrintStream out = System.out;

	public void _main(String[] args) {
		Scanner sc = new Scanner(in);

		int N = sc.nextInt();
		int M = sc.nextInt();

		List<List<Integer>> g = new ArrayList<>();
		for (int i = 0; i <= N; i++) {
			g.add(new ArrayList<>());
		}

		for (int i = 0; i < M; i++) {
			int a = sc.nextInt();
			int b = sc.nextInt();

			g.get(a).add(b);
			g.get(b).add(a);
		}

		sc.close();

		List<Integer> e = g.get(1);
		for (int x : e) {
			if (g.get(x).contains(N)) {
				out.println("POSSIBLE");
				return;
			}
		}
		out.println("IMPOSSIBLE");
	}

	public static void main(String[] args) {
		new Main()._main(args);
	}
}
