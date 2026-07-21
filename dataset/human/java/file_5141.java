import java.util.Scanner;

//AtCoder Beginner Contest 158
//D - String Formation
public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String S = sc.next();

		StringBuilder head = new StringBuilder();
		StringBuilder tail = new StringBuilder();
		int sw = -1; // -1:末尾 1:先頭

		int Q = Integer.parseInt(sc.next());
		for (int i = 0; i < Q; i++) {
			String t = sc.next();
			if (t.equals("1")) {
				sw *= -1;
			} else {
				String f = sc.next();
				String c = sc.next();
				if (sw == -1) {
					if (f.equals("2")) {
						// 末尾
						tail.append(c);
					} else {
						// 先頭
						head.append(c);
					}
				} else {
					if (f.equals("2")) {
						// 先頭
						head.append(c);
					} else {
						// 末尾
						tail.append(c);
					}
				}
			}

		}
		sc.close();
		if (sw == -1) {
			System.out.print(head.reverse().toString());
			System.out.print(S);
			System.out.print(tail.toString());
		} else {
			System.out.print(tail.reverse().toString());
			System.out.print(new StringBuilder(S).reverse().toString());
			System.out.print(head.toString());
		}
	}
}
