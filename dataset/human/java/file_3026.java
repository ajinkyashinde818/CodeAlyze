import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class Main {

	@SuppressWarnings("resource")
	public static void main(String args[]) {
		Scanner scanner = new Scanner(System.in);
		int n = scanner.nextInt();
		int m = scanner.nextInt();
		Set<Integer> j = new HashSet<>();
		boolean judge = true;

		for (int i = 0; i < m; i++) {
			int tmp1 = scanner.nextInt();
			int tmp2 = scanner.nextInt();
			if (tmp1 == 1 && judge) {
				if (j.contains(tmp2)) {
					judge = false;
					break;
				}
				j.add(tmp2);
			} else if (tmp2 == n && judge) {
				if (j.contains(tmp1)) {
					judge = false;
					break;
				}
				j.add(tmp1);
			}
		}

		if (judge) {
			System.out.println("IMPOSSIBLE");
		} else {
			System.out.println("POSSIBLE");
		}

	}
}
