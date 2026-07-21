import java.util.Scanner;

public class Main {
	static Scanner sc = new Scanner(System.in);

	public static void main(String[] args) {
		while (true) {
			int N = sc.nextInt();
			if (N == 0) break;
			int[] k = new int[N];
			for (int i = 0; i < N; ++i) {
				k[i] = sc.nextInt();
			}
			String s = sc.next();
			char[] ans = new char[s.length()];
			for (int i = 0; i < s.length(); ++i) {
				ans[i] = i2c(c2i(s.charAt(i)) + 52 - k[i % k.length]);
			}
			System.out.println(String.valueOf(ans));
		}
	}

	static int c2i(char c) {
		return 'a' <= c && c <= 'z' ? c - 'a' : c - 'A' + 26;
	}

	static char i2c(int i) {
		i %= 52;
		return (char) (i < 26 ? i + 'a' : i - 26 + 'A');
	}

}
