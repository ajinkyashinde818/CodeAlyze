import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;

public class Main {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String[] sa = br.readLine().split(" ");
		int n = Integer.parseInt(sa[0]);
		long k = Long.parseLong(sa[1]);
		sa = br.readLine().split(" ");
		int[] a = new int[n];
		for (int i = 0; i < n; i++) {
			a[i] = Integer.parseInt(sa[i]) - 1;
		}
		br.close();

		int[] c = new int[n];
		Arrays.fill(c, -1);
		int now = 0;
		c[now] = 0;
		int loop = 0;
		int in = 0;
		for (int i = 1; i <= n; i++) {
			now = a[now];
			if (i == k) {
				System.out.println(now + 1);
				return;
			}
			if (c[now] != -1) {
				in = now;
				loop = i - c[now];
				break;
			}
			c[now] = i;
		}

		int m = (int) (k % loop);
		boolean flg = false;
		now = 0;
		for (int i = 1; i <= k; i++) {
			now = a[now];
			if (now == in) {
				flg = true;
			}
			if (flg && i % loop == m) {
				System.out.println(now + 1);
				return;
			}
		}
	}
}
