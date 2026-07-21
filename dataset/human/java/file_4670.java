import java.util.Scanner;

public class Main {
	static Scanner sc = new Scanner(System.in);

	public static void main(String[] args) {
		while (true) {
			int N = sc.nextInt();
			if (N == 0) break;
			int K = sc.nextInt();
			int lo = 0;
			int hi = N;
			while (lo + 1 < hi) {
				int mid = (lo + hi) / 2;
				long c = count(mid);
				if (c < N) {
					lo = mid;
				} else {
					hi = mid;
				}
			}
			String ret = "";
			int start = (int) (N - count(lo) - 1);
			for (int i = 0; i < K + start; ++i) {
				ret += lo + 1 + i;
			}
			System.out.println(ret.substring(start, start + K));
		}
	}

	static long count(int n) {
		long base = 10;
		long ret = 0;
		int d = 1;
		for (; base <= n; ++d, base *= 10) {
			ret += d * (base - base / 10);
		}
		ret += d * (n - base / 10 + 1);
		return ret;
	}

}
