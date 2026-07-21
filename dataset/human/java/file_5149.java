import java.util.Scanner;

public class Main {

	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);
		StringBuffer s = new StringBuffer(sc.next());
		int q = sc.nextInt();

		int r = 1;

		for (int i = 0; i < q; i++) {
			int t = sc.nextInt();
			if (t == 1) {
				r *= -1;
			} else {
				int f = sc.nextInt();
				String c = sc.next();

				if ((r == 1 && f == 1) || r == -1 && f == 2) {
					s.insert(0, c);
				} else {
					s.append(c);
				}
			}
		}
		if ( r == -1) {
			s.reverse();
		}
		System.out.println(s);
	}

}
