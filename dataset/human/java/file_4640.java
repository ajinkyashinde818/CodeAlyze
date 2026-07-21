import java.util.ArrayDeque;
import java.util.Scanner;

public class Main {
	static Scanner sc = new Scanner(System.in);
	static int[] DR = { -1, -1, 0, 0, 1, 1 };
	static int[] DC = { -1, 0, -1, 1, 0, 1 };
	static int N, C;
	static int[][] S;

	public static void main(String[] args) {
		while (true) {
			N = sc.nextInt();
			if (N == 0) break;
			C = sc.nextInt();
			S = new int[N][N];
			for (int i = 0; i < N; ++i) {
				for (int j = 0; j <= i; ++j) {
					S[i][j] = sc.nextInt();
				}
			}
			System.out.println(solve());
		}
	}

	static int solve() {
		int ans = -9999;
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j <= i; ++j) {
				if (S[i][j] > 0) continue;
				S[i][j] = C;
				ans = Math.max(ans, count());
				S[i][j] = 0;
			}
		}
		return ans;
	}

	static int count() {
		int ret = 0;
		boolean[][] used = new boolean[N][N];
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j <= i; ++j) {
				if (S[i][j] == 0 || used[i][j]) continue;
				int c = 1;
				boolean live = false;
				ArrayDeque<Integer> q = new ArrayDeque<Integer>();
				q.add((i << 16) + j);
				used[i][j] = true;
				while (!q.isEmpty()) {
					int cur = q.poll();
					int cr = cur >> 16;
					int cc = cur & 0xFFFF;
					for (int k = 0; k < 6; ++k) {
						int nr = cr + DR[k];
						int nc = cc + DC[k];
						if (nr < 0 || N <= nr || nc < 0 || nr < nc) continue;
						if (used[nr][nc]) continue;
						if (S[nr][nc] == 0) {
							live = true;
							continue;
						}
						if (S[nr][nc] != S[i][j]) continue;
						used[nr][nc] = true;
						++c;
						q.add((nr << 16) + nc);
					}
				}
				if (!live) {
					ret += c * (S[i][j] == C ? -1 : 1);
				}
			}
		}
		return ret;
	}
}
