import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class Main {
	static List<Integer> path;

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String[] sa = br.readLine().split(" ");
		int n = Integer.parseInt(sa[0]);
		int k = Integer.parseInt(sa[1]);
		int l = Integer.parseInt(sa[2]);
		int[] a = new int[n];
		for (int i = 0; i < n; i++) {
			a[i] = i;
		}
		for (int i = 0; i < k; i++) {
			sa = br.readLine().split(" ");
			int p = Integer.parseInt(sa[0]) - 1;
			int q = Integer.parseInt(sa[1]) - 1;
			union(a, p, q);
		}

		int[] b = new int[n];
		for (int i = 0; i < n; i++) {
			b[i] = i;
		}
		for (int i = 0; i < l; i++) {
			sa = br.readLine().split(" ");
			int r = Integer.parseInt(sa[0]) - 1;
			int s = Integer.parseInt(sa[1]) - 1;
			union(b, r, s);
		}
		br.close();

		long[] key = new long[n];
		Map<Long, Integer> map = new HashMap<Long, Integer>();
		for (int i = 0; i < n; i++) {
			key[i] = find(a, i) * 1000000L + find(b, i);
			if (map.containsKey(key[i])) {
				map.put(key[i], map.get(key[i]) + 1);
			} else {
				map.put(key[i], 1);
			}
		}

		StringBuilder sb = new StringBuilder();
		for (int i = 0; i < n; i++) {
			sb.append(map.get(key[i])).append(' ');
		}
		sb.deleteCharAt(sb.length() - 1);
		System.out.println(sb.toString());
	}

	static void union(int[] parent, int x, int y) {
		int px = find(parent, x);
		int py = find(parent, y);
		if (px != py) {
			parent[px] = py;
		}
	}

	static int find(int[] parent, int x) {
		if (parent[x] == x) {
			return x;
		}
		parent[x] = find(parent, parent[x]);
		return parent[x];
	}
}
