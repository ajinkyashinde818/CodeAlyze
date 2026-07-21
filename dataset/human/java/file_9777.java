import java.util.*;

public class Main {
	void solve() {
		Scanner scan = new Scanner(System.in);
		int n = scan.nextInt();
		int m = scan.nextInt();
		int x = scan.nextInt();
		int[] c = new int[n];
		int[][] a = new int[n][m];
		for(int i = 0; i < n; i++) {
			c[i] = scan.nextInt();
			for(int j = 0; j < m; j++) {
				a[i][j] = scan.nextInt();
			}
		}
		ArrayList<Integer> money = new ArrayList<>();
		for(int i = 0; i < 1 << n; i++) {
			int[] sum = new int[m];
			boolean b = true;
			int cost = 0;
			for(int j = 0; j < n; j++) {
				if((1 & i >> j) == 1) {
					for(int k = 0; k < m; k++) {
						sum[k] += a[j][k];
					}
					cost += c[j];
				}
			}
			for(int j = 0; j < m; j++) {
				if(sum[j] < x) {
					b = false;
					break;
				}
			}
			if(b) {
				money.add(cost);
			}
		}
		if(money.isEmpty()) {
			System.out.println(-1);
			return;
		}
		Collections.sort(money);
		System.out.println(money.get(0));
		scan.close();
	}
	
	public static void main(String[] args) {
		new Main().solve();
	}
}
