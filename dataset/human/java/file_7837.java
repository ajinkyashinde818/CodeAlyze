import java.util.HashMap;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		int n = s.nextInt();
		long k = s.nextLong();
		int[] a = new int[n + 1];
		for(int i = 0; i < n; i++) {
			a[i + 1] = s.nextInt();
		}
		HashMap<Integer, Integer> map = new HashMap<Integer, Integer>();
		int start = 1;
		while(!map.containsKey(start) && k > 0) {
			map.put(start, map.size());
			start = a[start];
			k--;
		}
		if(k == 0) {
			System.out.println(start);
			return;
		}
		k %= (map.size() - map.get(start));
		map.clear();
//		System.out.println(map);
		while(!map.containsKey(start) && k > 0) {
			map.put(start, map.size());
			start = a[start];
			k--;
		}
		System.out.println(start);
	}

}
