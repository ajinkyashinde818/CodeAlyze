import java.util.Scanner;

public class Main {
	public static void main(String[] args) {

		Scanner scan = new Scanner(System.in);
		String S = scan.next();
		int Q = scan.nextInt();

		StringBuilder sb = new StringBuilder(S);
		StringBuilder sentou = new StringBuilder("");

		//true そのまま false 反転
		boolean flg = true;

		for (int i = 0; i < Q; i++) {

			if (scan.nextInt() == 1) {
				flg = !flg;
			} else {

				if (scan.nextInt() == 1) {
					if (flg)
						sentou.append(scan.next());
					else
						sb.append(scan.next());
				} else {
					if (flg)
						sb.append(scan.next());
					else
						sentou.append(scan.next());
				}
			}

		}

		S = sb.toString();
		StringBuffer sentousb = new StringBuffer(sentou.toString());
		String sentoustr = sentousb.reverse().toString();

		S = sentoustr + S;

		if (!flg) {
			StringBuffer strb = new StringBuffer(S);
			S = strb.reverse().toString();
		}
		System.out.println(S);
	}

}
