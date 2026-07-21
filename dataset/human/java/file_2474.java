import java.util.Scanner;

public class Main {
	static int a, n;

	static int getNumber(String a, char ch) {
		int index = a.indexOf(ch);
		int x = 0;
		if (index != -1) {
			x = 1;
			if (index != 0 && a.charAt(index - 1) >= '2'
					&& a.charAt(index - 1) <= '9') {
				x = a.charAt(index - 1) - '0';
			}
		}
		return x;
	}

	static String calc(String a, String b) {
		StringBuilder result = new StringBuilder();
		char[] charindex = { 'i', 'x', 'c', 'm' };

		int remain = 0;
		for (char c : charindex) {
			int anum = getNumber(a, c);
			int bnum = getNumber(b, c);
			int x = anum + bnum + remain;
			int reminder = x % 10;
			if (reminder != 0) {
				result.insert(0, c);
				if (reminder != 1) {
					result.insert(0, reminder);
				}
			}
			remain = x / 10;
		}

		return result.toString();
	}

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		for (int i = 0; i < n; i++) {
			String a = sc.next();
			String b = sc.next();
			System.out.println(calc(a, b));
		}
	}
}
