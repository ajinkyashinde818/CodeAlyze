import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String[] sa = br.readLine().split(" ");
		int k = Integer.parseInt(sa[0]);
		int n = Integer.parseInt(sa[1]);
		sa = br.readLine().split(" ");
		int[] a = new int[2 * n];
		for (int i = 0; i < n; i++) {
			a[i] = Integer.parseInt(sa[i]);
			a[n + i] = k + a[i];
		}
		br.close();

		int ans = k;
		for (int i = 0; i < n; i++) {
			ans = Math.min(ans, a[n + i - 1] - a[i]);
		}
		System.out.println(ans);
	}
}
