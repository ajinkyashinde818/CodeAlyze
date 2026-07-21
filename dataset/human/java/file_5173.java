import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		StringBuilder s1 = new StringBuilder(sc.next());
		StringBuilder s2 = new StringBuilder();

		int n = sc.nextInt();
		int rev = 0;

		for (int i = 0; i < n; i++) {
			int q = sc.nextInt();
			if (q == 1) {
				rev = 1 -rev;
			} else {
				int f = sc.nextInt();
				String c = sc.next();
				if (f == 1 && rev == 0 || f == 2 && rev ==1) {
					s2.append(c);
				} else {
					s1.append(c);
				}
			}
		}

		if (rev == 0) {
			System.out.println(s2.reverse().append(s1));
		} else {
			System.out.println(s2.reverse().append(s1).reverse());
		}

	}
}
