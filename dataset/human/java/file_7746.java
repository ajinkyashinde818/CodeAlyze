import java.util.HashMap;
import java.util.Scanner;

// https://atcoder.jp/contests/abc167/tasks/abc167_d
public class Main{

	public static void main(String[] args) {
		// TODO 自動生成されたメソッド・スタブ

		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		long k = sc.nextLong();
		int[] array = new int[n + 1];
		for (int i = 0; i < n; i++) {
			array[i] = sc.nextInt();
		}
		sc.close();

		int end = 0;

		array[n] = 1;
		HashMap<Integer, Integer> map = new HashMap<Integer, Integer>();
		int tmp = 1;
		map.put(tmp, 0);
		for (int i = 1; i <= n + 1; i++) {
			tmp = array[tmp - 1];
			if (map.containsKey(tmp)) {
				end = i;
				break;
			} else {
				map.put(tmp, i);
			}
		}

		long start = 0L;

		int tmp1 = 1;
		for (int i = 0; i <= n + 1; i++) {
			if (i == 0) {
				tmp1 = array[n];
			} else {
				tmp1 = array[tmp1 - 1];
			}
			if (tmp1 == tmp) {
				start = i;
				break;
			}
		}
		long rep = end - start;

		int ans = 1;

		if (k - start >= 0) {
			long aa = k - start;
			for (int i = 1; i <= start + aa % rep; i++) {
				ans = array[ans - 1];
			}
			System.out.println(ans);
		}else {
			for (int i = 1; i <= k; i++) {
				ans = array[ans - 1];
			}
			System.out.println(ans);
		}
		//		long aa = k - start;
		//		for (int i = 1; i <= start + aa % rep; i++) {
		//			ans = array[ans - 1];
		//		}
		//		System.out.println(ans);
	}
}
