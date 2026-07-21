import java.util.ArrayDeque;
import java.util.Deque;
import java.util.Scanner;

public class Main {
	static Scanner sc = new Scanner(System.in);

	public static void main(String[] args) {
		// TODO 自動生成されたメソッド・スタブ
		String s = sc.next();
		Deque<Character> deque = new ArrayDeque<Character>();
		boolean isDirectedForward = true;
		for (int i = 0, f = s.length(); i < f; ++i) {
			deque.addLast(s.charAt(i));
		}

		int q = Integer.parseInt(sc.next());
		for (int i = 0; i < q; ++i) {
			int t = Integer.parseInt(sc.next());
			if (t == 1) {
				isDirectedForward = !isDirectedForward;
				continue;
			}

			int f = Integer.parseInt(sc.next());
			char c = sc.next().charAt(0);
			if (f == 1) {
				if (isDirectedForward) {
					deque.addFirst(c);
				} else {
					deque.addLast(c);
				}
			} else {
				if (isDirectedForward) {
					deque.addLast(c);
				} else {
					deque.addFirst(c);
				}
			}
		}

		while (deque.size() > 0) {
			if (isDirectedForward) {
				System.out.print(deque.pollFirst());
			} else {
				System.out.print(deque.pollLast());
			}
		}
		System.out.println();
	}
}
