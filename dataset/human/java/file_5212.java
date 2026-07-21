import java.util.ArrayDeque;
import java.util.Deque;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		String S;
		int Q;
		int T;
		int F;
		String J;
		int flag = 0;
		int i;
		Scanner sc = new Scanner(System.in);
		S = sc.next();
		Q = Integer.parseInt(sc.next());
		Deque<String> deque = new ArrayDeque<String>();
		deque.addLast(S);
		for (i = 0; i < Q; i++) {
			T = Integer.parseInt(sc.next());
			if (T == 1) {
				if (flag == 0)
					flag = 1;
				else
					flag = 0;
			} else {
				F = Integer.parseInt(sc.next());
				J = sc.next();
				if (F == 1) {
					if (flag == 0)
						deque.addFirst(J);
					else
						deque.addLast(J);
				} else {
					if (flag == 0)
						deque.addLast(J);
					else
						deque.addFirst(J);
				}
			}
		}
		StringBuilder strBuf = new StringBuilder();
		while (deque.size() > 0) {
			strBuf.append(deque.removeFirst());
		}
		if (flag == 0)
			System.out.println(strBuf);
		else
			System.out.println(strBuf.reverse());
		sc.close();
	}
}
