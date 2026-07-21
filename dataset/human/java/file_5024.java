import java.util.Scanner;

public class Main {

	public static void main(String[] args) {

		boolean isReverce = false;

		Scanner sc = new Scanner(System.in);
		String s = sc.next();
		StringBuilder sb = new StringBuilder(s);
		StringBuilder front = new StringBuilder();
		int q = sc.nextInt();
		for (int i = 0; i < q; i++) {
			int t = sc.nextInt();
			if (t == 1) {
				isReverce = !isReverce;
			} else {
				int f = sc.nextInt();
				// String c = sc.next();
				if ((f == 1 && !isReverce) || (f == 2 && isReverce)) {
					front.append(sc.next());
				} else {
					sb.append(sc.next());
				}
			}
		}
		sc.close();

		if (isReverce) {
			print(sb.reverse().toString() + front.toString());
		} else {
			print(front.reverse().toString() + sb.toString());
		}
	}

	public static void print(Object obj) {
		System.out.println(obj);
	}

}
