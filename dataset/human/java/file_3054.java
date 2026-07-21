import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Deque;

public class Main {

	static ArrayList<Integer> alredy = new ArrayList<>();
	static Deque<Integer> stack = new ArrayDeque<>();
	static ArrayList<ArrayList<Integer>> list = new ArrayList<ArrayList<Integer>>();

	static int count = 0;
	static int n;

	static boolean flag = false;

	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		String str[] = br.readLine().split(" ");
		n = Integer.parseInt(str[0]);
		int m = Integer.parseInt(str[1]);

		for (int i = 0; i < n; i++) {
			list.add(new ArrayList<>());
		}

		for (int i = 0; i < m; i++) {
			str = br.readLine().split(" ");
			int a = Integer.parseInt(str[0]);
			int b = Integer.parseInt(str[1]);
			list.get(a - 1).add(b - 1);
		}
		dfs(0);
		if (flag) {
			System.out.println("POSSIBLE");
		} else {
			System.out.println("IMPOSSIBLE");
		}
	}

	static void dfs(int a) {
		stack.add(a);
		count++;
		while (!stack.isEmpty()) {
			int next = stack.poll();
			alredy.add(next);
			for (int i = 0; i < list.get(next).size(); i++) {
				int b = list.get(next).get(i);
				if (count <= 2) {
					if (b == n - 1) {
						flag = true;
						break;
					} else {
						dfs(b);
					}
				}
			}
			count = 0;
		}
	}
}
