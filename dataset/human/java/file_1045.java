import java.util.*;

public class Main {
	static final int MOD = 1000000007;
	public static void main (String[] args)  {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		char[] arr = sc.next().toCharArray();
		boolean flag = true;
		boolean[] isLefts = new boolean[2 * n];
		int leftCount = 0;
		for (int i = 0; i < 2 * n; i++) {
			if (i == 0) {
				isLefts[i] = true;
				leftCount++;
				if (arr[i] != 'B') {
					flag = false;
					break;
				}
			} else {
				if (arr[i] == arr[i - 1]) {
					isLefts[i] = !isLefts[i - 1];
				} else {
					isLefts[i] = isLefts[i - 1];
				}
				if (isLefts[i]) {
					leftCount++;
				}
			}
			if (i == 2 * n - 1 && ((arr[i] == 'W') || isLefts[i])) {
				flag = false;
			}
		}
		if (leftCount != n) {
			flag = false;
		}
		if (!flag) {
			System.out.println(0);
			return;
		}
		long total = 1;
		int lCount = 0;
		int rCount = 0;
		for (int i = 0; i < 2 * n; i++) {
			if (isLefts[i]) {
				lCount++;
			} else {
				total *= lCount - rCount;
				total %= MOD;
				rCount++;
			}
		}
		total *= kaijo(n);
		System.out.println(total % MOD);
	}
	
	static long kaijo(long x) {
		if (x == 0) {
			return 1;
		}
		long ans = x * kaijo(x - 1);
		return ans % MOD;
	}
}
