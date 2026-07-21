import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashSet;
import java.util.List;
import java.util.Queue;
import java.util.Scanner;
import java.util.Set;

public class Main {
	static int n;
	static int[] a, b;

	public static void main(String[] args) throws Exception {
		Scanner sc = new Scanner(System.in);
		n = sc.nextInt();
		a = new int[n];
		for (int i = 0; i < n; i++) {
			a[i] = sc.nextInt();
		}
		b = new int[n];
		for (int i = 0; i < n; i++) {
			b[i] = sc.nextInt();
		}
		sc.close();

		boolean[] use = new boolean[52];
		Arrays.fill(use, true);
		for (int i = 51; i > 0; i--) {
			use[i] = false;
			if (!judge(use)) {
				if (i == 51) {
					System.out.println(-1);
					return;
				}
				use[i] = true;
			}
		}

		long ans = 0;
		for (int i = 1; i < 51; i++) {
			if (use[i]) {
				ans += 1L << i;
			}
		}
		System.out.println(ans);
	}

	static boolean judge(boolean[] use) {
		List<Set<Integer>> list = new ArrayList<>(51);
		for (int i = 0; i < 51; i++) {
			list.add(new HashSet<>());
		}
		for (int i = 1; i < 51; i++) {
			for (int j = 1; j <= i; j++) {
				if (use[j]) {
					list.get(i).add(i % j);
				}
			}
		}

		for (int i = 0; i < n; i++) {
			boolean[] visit = new boolean[51];
			Queue<Integer> que = new ArrayDeque<>();
			que.add(a[i]);
			visit[a[i]] = true;
			while (!que.isEmpty()) {
				int cur = que.poll();
				for (int next : list.get(cur)) {
					if (next >= b[i] && !visit[next]) {
						que.add(next);
						visit[next] = true;
					}
				}
			}
			if (!visit[b[i]]) {
				return false;
			}
		}
		return true;
	}
}
