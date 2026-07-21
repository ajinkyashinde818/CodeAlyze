import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;

public class Main {

	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		String str[] = br.readLine().split(" ");

		int n = Integer.parseInt(str[0]);
		int k = Integer.parseInt(str[1]);
		int l = Integer.parseInt(str[2]);

		UnionFindTree uf1 = new UnionFindTree(n);
		UnionFindTree uf2 = new UnionFindTree(n);

		for (int i = 0; i < k; i++) {
			str = br.readLine().split(" ");

			int p = Integer.parseInt(str[0]) - 1;
			int q = Integer.parseInt(str[1]) - 1;

			uf1.union(p, q);
		}

		for (int i = 0; i < l; i++) {
			str = br.readLine().split(" ");

			int r = Integer.parseInt(str[0]) - 1;
			int s = Integer.parseInt(str[1]) - 1;

			uf2.union(r, s);
		}

		HashMap<Long, Integer> map = new HashMap<>();
		for (int i = 0; i < n; i++) {
			long key = uf1.find(i) * (long) n + uf2.find(i);
			if (map.containsKey(key)) {
				map.put(key, map.get(key) + 1);
			} else {
				map.put(key, 1);
			}
		}
		StringBuilder sb = new StringBuilder();
		for (int i = 0; i < n; i++) {
			if (i != 0) {
				sb.append(" ");
			}
			long key = uf1.find(i) * (long) n + uf2.find(i);
			sb.append(map.get(key));
		}
		System.out.print(sb);
	}
}

class UnionFindTree {

	int[] parent;
	int[] rank;

	public UnionFindTree(int size) {
		this.parent = new int[size];
		this.rank = new int[size];

		for (int i = 0; i < size; i++) {
			makeSet(i);
		}
	}

	public void makeSet(int i) {
		parent[i] = i;
		rank[i] = 0; // 集合の高さ
	}

	public void union(int x, int y) {
		int xRoot = find(x);
		int yRoot = find(y);

		// xが属する木の方が大きい場合
		if (rank[xRoot] > rank[yRoot]) {
			parent[yRoot] = xRoot; // yの親をxに更新

		} else if (rank[xRoot] < rank[yRoot]) {
			parent[xRoot] = yRoot;

		} else if (xRoot != yRoot) {
			parent[yRoot] = xRoot;
			rank[xRoot]++; // 同じ高さの木がルートの子として着くから大きさ++;
		}
	}

	// 引数の属する木のルートのidを返す
	public int find(int i) {
		if (i != parent[i]) {
			parent[i] = find(parent[i]);
		}
		return parent[i];
	}

	// 同じ木に属しているか
	public boolean same(int x, int y) {
		return find(x) == find(y);
	}
}
