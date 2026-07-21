import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String s = sc.next();
		int q = sc.nextInt();
		boolean hanten = false;
		StringBuilder sb = new StringBuilder();
		StringBuilder sb2 = new StringBuilder();
		for (int i = 0; i < q; i++) {
			int t = sc.nextInt();
			if (t == 1) {
				hanten = !hanten;
			} else {
				int f = sc.nextInt();
				String c = sc.next();
				if (f == 1) {
					if (hanten) {
						sb2.append(c);
					} else {
						sb.append(c);
					}
				} else {
					if (hanten) {
						sb.append(c);
					} else {
						sb2.append(c);
					}
				}
			}
		}
		sb.reverse().append(s).append(sb2.toString());
		if (hanten) {
			sb.reverse();
		}
		System.out.println(sb.toString());
		sc.close();
	}
}
