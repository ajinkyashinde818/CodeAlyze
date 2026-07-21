import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		String string = sc.next();
		int N = Integer.parseInt(sc.next());
		boolean switchFlg = false;
		StringBuilder sb = new StringBuilder(string);

		for (int i = 0; i < N; i++) {
			int T =sc.nextInt();
			if (T == 1) {
				if (switchFlg) {
					switchFlg = false;
				}else {
					switchFlg = true;
				}
			}else {
				int F = sc.nextInt();
				if ((F == 1 && switchFlg == false) || (F == 2 && switchFlg == true)) {
					String top = sc.next();
					sb.insert(0, top);
				}else if ((F == 1 && switchFlg == true) || (F == 2 && switchFlg == false)) {
					String end = sc.next();
					sb.append(end);
				}
			}
		}

		if (switchFlg) {
			System.out.println(sb.reverse().toString());
		}else {
			System.out.println(sb.toString());
		}

	}
}
