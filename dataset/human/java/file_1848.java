import java.util.Scanner;

public class Main {

	static boolean[] used;

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int d = sc.nextInt();
		int g = sc.nextInt();
		int[] p = new int[d];
		int[] c = new int[d];
		// used[i]：i番目の問題を選択したかどうか
		used = new boolean[d];
		for(int i = 0; i < d; i++) {
			p[i] = sc.nextInt();
			c[i] = sc.nextInt();
		}
		int ans = Integer.MAX_VALUE;
//		System.out.println(1<<d);
		for(int mask = 0; mask < (1<<d); mask++) {
//			System.out.println(Integer.toBinaryString(mask));
			int cnt = 0;
			long point = 0;
			for(int i = 0; i < d; i++) used[i] = false;
			for(int i = 0; i < d; i++) {
				if((mask&(1<<i)) >= 1) {
					used[i] = true;
					point += 100 * (i + 1) * p[i] + c[i];
					cnt += p[i];
				}
			}
			if(point >= g) {
				ans = Integer.min(ans, cnt);
//				System.out.println(ans + " " + point + " " + mask);
				continue;
			}
			for(int i = d - 1; i >= 0; i--) {
				// このループの内側のループからこのループの外側のループに戻るかどうかの判定
				boolean ok = false;
				if(!used[i]) {
					for(int j = 0; j < p[i]; j++) {
						point += (i + 1) * 100;
						cnt++;
						if(j == p[i] - 1) point += c[i];
						if(point >= g) {
							ans = Integer.min(ans, cnt);
							ok = true;
							break;
						}
					}
				}
				if(ok) break;
			}
		}
		System.out.println(ans);
	}
}
