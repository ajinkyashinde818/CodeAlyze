import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String S = sc.next();
		char[] c = S.toCharArray();
		sc.close();
		int aa = 0, bb = 0, cc = 0;
		for (int i = 0; i < 3; i++) {
			if (c[i] == 'a') {
				aa++;
			} else if (c[i] == 'b') {
				bb++;
			} else {
				cc++;
			}
		}
		if (aa == 1 && bb == 1 && cc == 1) {
			System.out.println("Yes");
		} else {
			System.out.println("No");
		}
	}
}
