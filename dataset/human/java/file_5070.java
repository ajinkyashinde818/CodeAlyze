import java.util.Scanner;

public class Main {

	public static void main(String[] args) {

		Scanner scan = new Scanner(System.in);

		StringBuffer S = new StringBuffer(scan.next());
		int Q = scan.nextInt();
		int f = 0;

		for (int i = 0; i < Q; i ++) {
			int t = scan.nextInt();

			if (t == 1) {
				f++;
			} else {
				int F = scan.nextInt();
				String C = scan.next();

				if (f % 2 == 0) {
					if (F == 1) {
						S.insert(0, C);
					} else {
						S.insert(S.length(), C);
					}
				} else {
					if (F == 2) {
						S.insert(0, C);
					} else {
						S.insert(S.length(), C);
					}
				}
			}
		}

		if (f % 2 == 1) {
			S.reverse();
		}

		System.out.println(S);

	}

}
