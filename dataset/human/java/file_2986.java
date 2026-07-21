import java.util.ArrayList;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int N = in.nextInt();
		int M = in.nextInt();
		Map<Integer, ArrayList<Integer>> map = new HashMap<>();
		for (int i = 0; i < M; i++) {
			int a = in.nextInt();
			int b = in.nextInt();
			if (map.containsKey(a)) {
				ArrayList<Integer> to = map.get(a);
				to.add(b);
			} else {
				ArrayList<Integer> to = new ArrayList<>();
				to.add(b);
				map.put(a, to);
			}
		}
		String ans = "IMPOSSIBLE";
		ArrayList<Integer> list = map.get(1);
		for (Integer from : list) {
			if (map.containsKey(from)) {
				if (map.get(from).contains(N)) {
					ans = "POSSIBLE";
					break;
				}
			}
		}
		System.out.println(ans);
		in.close();
	}
}
