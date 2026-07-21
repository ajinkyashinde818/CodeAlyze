import java.util.Scanner;

public class Main {
	public static void main(String... args) {
		Scanner scan = new Scanner(System.in);
		String s = scan.next();

		StringBuffer sb1 = new StringBuffer();
		StringBuffer sb2 = new StringBuffer();

		boolean reverse = false;
		int n = scan.nextInt();
		for (int i = 0; i < n; i++) {
			int q = scan.nextInt();
			if (q == 1) {
				reverse = !reverse;
			} else {
				int f = scan.nextInt();
				String c = scan.next();
				if (f == 1 ^ reverse) {
					sb1.append(c);
				} else {
					sb2.append(c);
				}
			}
		}

		StringBuffer sb = new StringBuffer();
		sb1.reverse();
		sb.append(sb1);
		sb.append(s);
		sb.append(sb2);
		if (reverse) {
			sb.reverse();
		}

		System.out.println(sb.toString());
		scan.close();
	}
}
