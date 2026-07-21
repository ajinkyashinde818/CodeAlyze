import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		// TODO 自動生成されたメソッド・スタブ
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		long k = sc.nextLong();
		int[] to = new int[n + 10];
		for (int i = 1; i <= n; ++i) {
			to[i] = sc.nextInt();
		}

		int[] visited = new int[n + 10];
		int current = 1, stepCnt = 0;
		while (visited[current] < 1) {
			++visited[current];
			current = to[current];
			++stepCnt;

			if (stepCnt == k) {
				System.out.println(current);
				return;
			}
		}

		int cycleLen = 0;
		while (visited[current] < 2) {
			++visited[current];
			current = to[current];
			++stepCnt;
			++cycleLen;

			if (stepCnt == k) {
				System.out.println(current);
				return;
			}
		}

		k -= stepCnt;
		k %= cycleLen;
		while (k > 0) {
			current = to[current];
			--k;
		}

		System.out.println(current);
	}

}
