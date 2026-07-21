import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.Scanner;
import java.util.Set;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int M = sc.nextInt();
		int[]a = new int[M];
		int[]b = new int[M];
		Map<Integer, Set<Integer>> map = new HashMap<Integer, Set<Integer>>();
		for(int i = 0; i < M; i++) {
			a[i] = sc.nextInt();
			b[i] = sc.nextInt();
		}
		sc.close();
		for(int i = 0; i < M; i++) {
			if(map.containsKey(a[i])) {
				map.get(a[i]).add(b[i]);
			}else {
				Set<Integer> set = new HashSet<Integer>();
				set.add(b[i]);
				map.put(a[i], set);
			}
		}
		if(!map.containsKey(1)) {
			System.out.println("IMPOSSIBLE");
			System.exit(0);
		}
		Set<Integer> set = map.get(1);
		for(int i : set) {
			if(map.containsKey(i)) {
				if(map.get(i).contains(N)) {
					System.out.println("POSSIBLE");
					System.exit(0);
				}
			}
		}
		System.out.println("IMPOSSIBLE");
	}
}
