import java.util.ArrayDeque;
import java.util.Arrays;
import java.util.Deque;
import java.util.List;
import java.util.Scanner;
import java.util.stream.Collectors;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String s = sc.nextLine();
		Deque<String> dq = new ArrayDeque<>(Arrays.asList(s.split("")));
		int n = Integer.valueOf(sc.nextLine());
		boolean isReverse = false;
		for (int i = 0; i < n; i++) {
			if ("1".equals(sc.next())) {
				// que反転
				isReverse = !isReverse;
			} else {
				// 向きを示す物が必要
				if ("1".equals(sc.next()) == isReverse) {
					// 後ろ
					dq.addLast(sc.next());
				} else {
					// 前
					dq.addFirst(sc.next());
				}
			}
		}
		StringBuilder sb = new StringBuilder();
		int size = dq.size();
		for (int i = 0; i < size; i++) {
			if (isReverse) {
				sb.append(dq.pollLast());
			} else {
				sb.append(dq.pollFirst());
			}
		}

		System.out.println(sb.toString());
	}
}
