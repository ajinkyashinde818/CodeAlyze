import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		try (Scanner scanner = new Scanner(System.in)) {
			StringBuilder sb = new StringBuilder(scanner.next());
			StringBuilder prefix = new StringBuilder();
			int q = scanner.nextInt();
			boolean reverse = false;
			for (int i = 0; i < q; i++) {
				switch (scanner.nextInt()) {
				case 1:
					reverse = !reverse;
					break;
				case 2:
					int f = scanner.nextInt();
					String c = scanner.next();
					if (1 == f) {
						if (reverse) {
							sb.append(c);
						} else {
							prefix.append(c);
						}
					} else {
						if (reverse) {
							prefix.append(c);
						} else {
							sb.append(c);
						}
					}
				}
			}
			System.out.println((reverse ? sb.reverse().append(prefix) : prefix.reverse().append(sb)).toString());
		}
	}
}
