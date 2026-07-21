import java.util.Scanner;

public class Main {
	public static void main(String[] args) throws Exception {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		char[] s = sc.next().toCharArray();
		sc.close();

		int l = 0;
		int r = 2 * n - 1;
		while (l < r - 1) {
			if (s[l] == 'W') {
				System.out.println(0);
				return;
			} else if (s[l] == 'B' && s[l + 1] == 'B') {
				l += 2;
			} else {
				break;
			}
		}
		while (l < r - 1) {
			if (s[r] == 'W') {
				System.out.println(0);
				return;
			} else if (s[r] == 'B' && s[r - 1] == 'B') {
				r -= 2;
			} else {
				break;
			}
		}

		int cnt = 0;
		int[] a = new int[2 * n];
		for (int i = l; i <= r; i++) {
			if (cnt % 2 == 0) {
				if (s[i] == 'B') {
					a[i] = 1;
					cnt++;
				} else {
					a[i] = -1;
					cnt--;
				}
			} else {
				if (s[i] == 'B') {
					a[i] = -1;
					cnt--;
				} else {
					a[i] = 1;
					cnt++;
				}
			}
		}
		if (cnt != 0) {
			System.out.println(0);
			return;
		}

		int mod = 1000000007;
		long ans = 1;
		for (int i = l; i <= r; i++) {
			if (a[i] == 1) {
				cnt++;
			} else if (a[i] == -1) {
				ans *= cnt;
				ans %= mod;
				cnt--;
			}
		}
		long p = 1;
		for (int i = 1; i <= n; i++) {
			p *= i;
			p %= mod;
		}
		System.out.println(ans * p % mod);
	}
}
