import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		String s = sc.next();

		int headIdx = 0;
		int tailIdx = s.length() - 1;
		int headSkip = 0;
		int tailSkip = 0;
		int ans = 0;
		while (true) {
			while (s.charAt(headIdx) == 'x' && headIdx < s.length() - 1) {
				headIdx++;
				headSkip++;
			}
			while (s.charAt(tailIdx) == 'x' && tailIdx > 0) {
				tailIdx--;
				tailSkip++;
			}
			if (s.charAt(headIdx) != s.charAt(tailIdx)) {
				System.out.print(-1);
				return;
			} else if (headIdx >= tailIdx) {
				ans += Math.abs(headSkip - tailSkip);
				break;
			} else {
				ans += Math.abs(headSkip - tailSkip);
				headSkip = 0;
				tailSkip = 0;
				headIdx++;
				tailIdx--;
			}
		}

		System.out.print(ans);
	}

}
