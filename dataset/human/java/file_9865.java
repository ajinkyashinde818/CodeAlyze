import java.util.*;
 
public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int m = sc.nextInt();
		int x = sc.nextInt();
		int[][] skills = new int[n][m];
		int[] cost = new int[n];
		for (int i = 0; i < n; i++) {
			cost[i] = sc.nextInt();
			for (int j = 0; j < m; j++) {
				skills[i][j] = sc.nextInt();
			}
		}

		int maxMaskN = 1 << n;
		int ans = Integer.MAX_VALUE;
		for (int mask = 0; mask < maxMaskN; mask++) {
			int[] learn = new int[m];
			int total = 0;
			for (int i = 0; i < n; i++) {
				// chosen
				if (((mask >> i) & 1) == 1) {
					total += cost[i];
					for (int j = 0; j < m; j++) {
						learn[j] += skills[i][j];
					}
				}
			}
			if (isValid(learn, x)) {
				ans = Math.min(ans, total);
			}
		}
		if (ans == Integer.MAX_VALUE) {
			ans = -1;
		}
		System.out.println(ans);
	}

	private static boolean isValid(int[] arr, int k) {
		for (int i = 0; i < arr.length; i++) {
			if (arr[i] < k) {
				return false;
			}
		}
		return true;
	}
}
