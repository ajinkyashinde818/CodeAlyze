import java.util.*;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		ArrayDeque<String> deque = new ArrayDeque<String>();
		String s = sc.next();

		int q = sc.nextInt();
		int top = 1; // 反転情報を持つ
		deque.add(s);

		for (int i = 0; i < q; i++) {
			int t = sc.nextInt();
			if (t == 1) {
				top *= -1; // 反転情報を更新
			} else {
				int f = sc.nextInt();
				String c = sc.next();
				if (f == 1) { // 先頭にcを追加
					if (top > 0) {
						deque.addFirst(c);
					} else {
						deque.addLast(c);
					}
				} else { // 末尾にcを追加
					if (top > 0) {
						deque.addLast(c);
					} else {
						deque.addFirst(c);
					}
				}
			}
		}
		// 出力
		StringBuffer sb = new StringBuffer();
		int m = deque.size();
		for (int i = 0; i < m; i++) {
			sb.append(deque.pollFirst());
		}
		if (top < 0) {
			sb.reverse();
		}

		System.out.println(sb.toString());
		sc.close();
	}
}
