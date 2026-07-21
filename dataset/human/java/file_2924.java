import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		int m = in.nextInt();
		int a, b;
		Map<Integer, HashSet<Integer>> mp = new HashMap<>();
		for (int i = 0; i < m; i++) {
			a = in.nextInt();
			b = in.nextInt();
			HashSet<Integer> s1 = null, s2 = null;
			if (mp.get(a) != null) {
				s1 = mp.get(a);
			}
			if (mp.get(b) != null) {
				s2 = mp.get(b);
			}
			if (mp.get(a) == null) {
				s1 = new HashSet<Integer>();
			}
			if (mp.get(b) == null) {
				s2 = new HashSet<Integer>();
			}
			s1.add(b);
			s2.add(a);
			mp.put(a, s1);
			mp.put(b, s2);
		}
		for (Integer x : mp.get(1)) {
			if (mp.get(x).contains(n)) {
				System.out.println("POSSIBLE");
				System.exit(0);
			}
		}
		System.out.println("IMPOSSIBLE");

		in.close();
	}
}
