import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Map;
import java.util.TreeSet;

public class Main {
	static int[] c;
	static Map<Integer, TreeSet<Integer>> mapc;

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());
		String[] sa = br.readLine().split(" ");
		int[] a = new int[n];
		for (int i = 0; i < n; i++) {
			a[i] = Integer.parseInt(sa[i]);
		}
		sa = br.readLine().split(" ");
		int[] b = new int[n];
		for (int i = 0; i < n; i++) {
			b[i] = Integer.parseInt(sa[i]);
		}
		br.close();

		c = new int[n + 1];
		for (int i = 0; i < n; i++) {
			c[a[i]]++;
			c[b[i]]++;
		}
		for (int i = 1; i <= n; i++) {
			if (c[i] > n) {
				System.out.println("No");
				return;
			}
		}
		System.out.println("Yes");

		reverse(b);
		int j = 0;
		for (int i = 0; i < n; i++) {
			if (a[i] == b[i]) {
				for ( ; j < n; j++) {
					if (a[j] != b[i] && a[i] != b[j]) {
						int tmp = b[j];
						b[j] = b[i];
						b[i] = tmp;
						break;
					}
				}
			}
		}

		StringBuilder sb = new StringBuilder();
		for (int i = 0; i < n; i++) {
			sb.append(b[i]).append(' ');
		}
		sb.deleteCharAt(sb.length() - 1);
		System.out.println(sb.toString());
	}

	static void reverse(int[] a) {
		for (int i = 0; i < a.length / 2; i++) {
			int tmp = a[i];
			a[i] = a[a.length - 1 - i];
			a[a.length - 1 - i] = tmp;
		}
	}
}
