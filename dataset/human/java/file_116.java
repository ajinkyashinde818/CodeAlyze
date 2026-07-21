import java.util.*;

/**
 * Main
 */
public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		// 整数の入力
		int N = sc.nextInt();
		long ans = 0L;
		long min = 100000000000L;
		int count = 0;

		for (int i = 0; i < N; i++) {
			long X = sc.nextLong();
			if (X < 0) {
				count++;
			}
			min = Math.min(min, Math.abs(X));
			ans += Math.abs(X);
		}
		if (count % 2 == 0) {
			System.out.println(ans);
		} else {
			System.out.println(ans - 2 * min);
		}

		sc.close();
	}
};
