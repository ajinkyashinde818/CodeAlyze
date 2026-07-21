import java.util.Scanner;

public class Main {
	public static void main(String[] args) throws Exception {
		Scanner sc = new Scanner(System.in);
		StringBuilder sb = new StringBuilder(sc.next());
		sc.close();

		sb.reverse();
		String s = sb.toString();
		int n = s.length();
		String[] sa = {"maerd", "remaerd", "esare", "resare"};
		int idx = 0;
		while (idx < n) {
			boolean flg = false;
			for (int i = 0; i < sa.length; i++) {
				if (s.indexOf(sa[i], idx) == idx) {
					idx += sa[i].length();
					flg = true;
					break;
				}
			}
			if (!flg) {
				System.out.println("NO");
				return;
			}
		}
		System.out.println("YES");
	}
}
