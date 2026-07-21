import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.List;

public class Main {
	static int v = 0;
	static List<List<Integer>> ansList = null;

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		char[] s = br.readLine().toCharArray();
		br.close();

		int ans = 0;
		int l = 0;
		int r = s.length - 1;
		while (l < r) {
			if (s[l] == s[r]) {
				l++;
				r--;
			} else if (s[l] == 'x') {
				ans++;
				l++;
			} else if (s[r] == 'x') {
				ans++;
				r--;
			} else {
				System.out.println(-1);
				return;
			}
		}
		System.out.println(ans);
	}
}
