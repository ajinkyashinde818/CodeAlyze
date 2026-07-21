import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		String S = in.next();
		boolean isOk = false;
		String[] divide = { "dream", "dreamer", "erase", "eraser" };
		int t = S.length();
		while (true) {
			for (String s : divide) {
				if (t - s.length() >= 0 && S.substring(t - s.length(), t).equals(s)) {
					isOk = true;
					t -= s.length();
					break;
				} else {
					isOk = false;
				}
			}
			if (!isOk || t == 0) {
				break;
			}
		}
		System.out.println(isOk ? "YES" : "NO");
		in.close();
	}
}
