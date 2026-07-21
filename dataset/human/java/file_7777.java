import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		long K = sc.nextLong();
		int[] A = new int[N];
		for (int i = 0; i < N; i++) {
			A[i] = sc.nextInt() - 1;
		}
		Map<Integer, Integer> map = new HashMap<Integer, Integer>();
		int s = 0;
		while (!map.containsKey(s)) {
			map.put(s, A[s]);
			s = A[s];
		}
		int c = 0;
		int p = 0;
		while (p != s) {
			 p = map.get(p);
			 c++;
		}
		if (K >= c) {
			long count = (K - c) % (map.size() - c);
			int ans = s;
			while (count > 0) {
				ans = map.get(ans);
				count--;
			}
			System.out.println(ans + 1);
		} else {
			long count = K;
			int ans = 0;
			while (count > 0) {
				ans = map.get(ans);
				count--;
			}
			System.out.println(ans + 1);
		}
	}

}
