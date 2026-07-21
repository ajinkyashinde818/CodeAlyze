import java.io.IOException;
import java.util.ArrayDeque;
import java.util.Deque;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		String stations = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

		while (true) {
			int n = scanner.nextInt();
			if (n == 0) {
				break;
			}
			Deque<Integer> deque = new ArrayDeque<Integer>();

			for (int i = 0; i < n; i++) {
				deque.addFirst(scanner.nextInt());
			}

			String list = scanner.next();
			for (int i = 0; i < list.length(); i++) {
				int s = stations.indexOf(list.substring(i, i + 1));

				int key = deque.pollLast();
				deque.addFirst(key);

				s -= key;
				if (s < 0) {
					s += 52;
				}

				System.out.print(stations.substring(s, s + 1));
			}
			System.out.print("\n");
		}

	}

	static int nextInt() {
		int c;
		try {
			c = System.in.read();
			while (c != '-' && (c < '0' || c > '9'))
				c = System.in.read();
			if (c == '-')
				return -nextInt();
			int res = 0;
			while (c >= '0' && c <= '9') {
				res = res * 10 + c - '0';
				c = System.in.read();
			}
			return res;
		} catch (IOException e) {
			e.printStackTrace();
		}
		return -1;
	}

}
