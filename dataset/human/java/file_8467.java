import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.HashMap;
import java.util.HashSet;

public final class Main {

	class UnionFind {
		int[] arr;

		public UnionFind(int size) {
			arr = new int[size];
			for (int i = 0; i < size; i++) {
				arr[i] = -1;
			}
		}

		public int find(int x) {
			if (arr[x] == -1)
				return x;
			int temp = x;
			while (arr[temp] != -1) {
				temp = arr[temp];
			}
			int root = temp;
			temp = x;
			while (arr[temp] != -1) {
				temp = arr[x];
				arr[x] = root;
			}
			return root;
		}

		public int union(int x, int y) {
			int rx = find(x);
			int ry = find(y);
			if (rx == ry)
				return 0;
			if (Math.abs(rx) > Math.abs(ry)) {
				arr[ry] = rx;
			} else if (Math.abs(rx) < Math.abs(ry)) {
				arr[rx] = ry;
			} else {
				arr[rx] = ry;
				arr[ry] += 1;
			}
			return 1;
		}
	}

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String[] in = br.readLine().split(" ");
		int n = Integer.parseInt(in[0]);
		int k = Integer.parseInt(in[1]);
		int l = Integer.parseInt(in[2]);
		UnionFind road = new Main().new UnionFind(n);
		UnionFind rail = new Main().new UnionFind(n);
		for (int i = 0; i < k; i++) {
			in = br.readLine().split(" ");
			road.union(Integer.parseInt(in[0]) - 1, Integer.parseInt(in[1]) - 1);
		}
		for (int i = 0; i < l; i++) {
			in = br.readLine().split(" ");
			rail.union(Integer.parseInt(in[0]) - 1, Integer.parseInt(in[1]) - 1);
		}
		int[] ans = new Solver().solve(road, rail, n);
		Arrays.stream(ans).mapToObj(e -> e + " ").forEachOrdered(System.out::print);

	}
}

class Solver {

	int[] solve(Main.UnionFind road, Main.UnionFind rail, int n) {
		int ans[] = new int[n];
		HashMap<Integer, HashSet<Integer>> roadComps = new HashMap<Integer, HashSet<Integer>>();
		for (int i = 0; i < n; i++) {
			int rt = road.find(i);
			if (!roadComps.containsKey(rt)) {
				roadComps.put(rt, new HashSet<Integer>());
			}
			roadComps.get(rt).add(i);
		}
		for (HashSet<Integer> set : roadComps.values()) {
			HashMap<Integer, HashSet<Integer>> railComps = new HashMap<Integer, HashSet<Integer>>();
			for (int entry : set) {
				int root = rail.find(entry);
				if (!railComps.containsKey(root)) {
					railComps.put(root, new HashSet<Integer>());
				}
				railComps.get(root).add(entry);
			}
			for (HashSet<Integer> res : railComps.values()) {
				int len = res.size();
				for (int resi : res) {
					ans[resi] = len;
				}
			}
		}

		return ans;

	}

}
