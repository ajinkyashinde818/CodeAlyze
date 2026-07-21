import java.util.Scanner;

public class Main {

	public static void main(String[] args) {

		Scanner scanner = new Scanner(System.in);
		String answer = scanner.next();
		int Q = scanner.nextInt();
		boolean didReverse = false;
		StringBuilder head = new StringBuilder();
		StringBuilder tail = new StringBuilder();

		for (int i = 0; i < Q; i++) {
			int T = scanner.nextInt();
			if (T == 1) didReverse = !didReverse;
			else {
				int F = scanner.nextInt();
				String C = scanner.next();
				if ((F == 1 && !didReverse) || (F == 2 && didReverse)) head.append(C);
				else tail.append(C);
			}
		}

		answer = head.reverse().append(answer).append(tail).toString();
		if (didReverse) {
			StringBuilder sb = new StringBuilder(answer);
			answer = sb.reverse().toString();
		}

		System.out.println(answer);
	}
}
