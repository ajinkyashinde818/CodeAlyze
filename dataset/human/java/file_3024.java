import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String[] sa = br.readLine().split(" ");
		int n = Integer.parseInt(sa[0]);
		int m = Integer.parseInt(sa[1]);
		int[] a = new int[m];
		int[] b = new int[m];
		for (int i = 0; i < m; i++) {
			sa = br.readLine().split(" ");
			a[i] = Integer.parseInt(sa[0]) - 1;
			b[i] = Integer.parseInt(sa[1]) - 1;
		}
		br.close();

		boolean[] ok = new boolean[n];
		for (int i = 0; i < m; i++) {
			if (a[i] == 0) {
				ok[b[i]] = true;
			}
		}
		for (int i = 0; i < m; i++) {
			if (b[i] == n - 1 && ok[a[i]]) {
				System.out.println("POSSIBLE");
				return;
			}
		}
		System.out.println("IMPOSSIBLE");
	}
}
