import java.util.Scanner;

public class Main {

	/**
	 * @param args
	 *
	 */
	Scanner sc = new Scanner(System.in);

	void run() {
		char[] cs = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"
				.toCharArray();

		while (true) {
			int n = sc.nextInt();
			if (n == 0)
				break;
			int[] ks = new int[n];
			for (int i = 0; i < n; i++) {
				ks[i] = sc.nextInt();
			}
			char[] list = sc.next().toCharArray();
			char[] ans = new char[list.length];
			int kidx = 0;
			for (int i = 0; i < list.length; i++) {
				int idx = 0;
				if (list[i] >= 'A' && list[i] <='Z') {
					idx = list[i] - 'A' + 26;
				} else {
					idx = list[i] - 'a';
				}
				int nidx = (idx - ks[kidx] + 52) % 52;
				if (nidx >= 26) {
					ans[i] = (char) ('A' + nidx - 26);
				} else {

					ans[i] = (char) ('a' + nidx);
				}

				kidx += 1;
				kidx %= n;
			}

			System.out.println(new String(ans));
		}

	}

	public static void main(String[] args) {
		// TODO 自動生成されたメソッド・スタブ
		new Main().run();

	}

}
