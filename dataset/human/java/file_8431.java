import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.TreeMap;

public class Main {
	static int n;
	static int[] a;
	static TreeMap<Integer, Integer> map;

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		n = Integer.parseInt(br.readLine());
		String[] sa = br.readLine().split(" ");
		a = new int[n];
		for (int i = 0; i < n; i++) {
			a[i] = Integer.parseInt(sa[i]);
		}
		br.close();

		int ok = n + 1;
		int ng = 0;
		while (Math.abs(ok - ng) > 1) {
			int mid = (ok + ng) / 2;
			if (judge(mid)) {
				ok = mid;
			} else {
				ng = mid;
			}
		}
		System.out.println(ok);
	}

	static boolean judge(int mid) {
		map = new TreeMap<>();
		for (int i = 0; i < n; i++) {
			Integer ce = map.ceilingKey(a[i]);
			if (ce == null) {
				Integer lo = map.lowerKey(a[i]);
				if (lo != null) {
					if (map.get(lo) == 1) {
						map.remove(lo);
					}
				}
				map.put(a[i], 1);
			} else {
				boolean res = update(a[i], ce, mid);
				if (!res) {
					return false;
				}
			}
		}
		return true;
	}

	static boolean update(int ai, int ce, int mid) {
		Integer[] arr = map.descendingKeySet().toArray(new Integer[0]);
		for (Integer k : arr) {
			if (k > ce) {
				continue;
			}
			int v = map.get(k);
			if (k == ce) {
				k = ai;
			}
			if (v < mid) {
				map.put(k, v + 1);
				if (k > 1) {
					if (map.containsKey(k - 1)) {
						if (map.get(k - 1) == v + 1) {
							map.remove(k - 1);
						}
					} else {
						map.put(k - 1, v);
					}
				}
				map.tailMap(k + 1).clear();
				if (k < ai) {
					map.put(ai, 1);
				}
				return true;
			}
		}
		return false;
	}
}
