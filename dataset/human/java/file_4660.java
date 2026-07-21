import java.util.Scanner;

public class Main {

	static boolean f(int w, int[] book, int n, int m) {
		int need = 0;
		int s = w;
		int i = 0;
		while (i != m) {
			if (need == n)
				return false;
			if (s - book[i] >= 0) {
				s -= book[i];
				i++;
			} else {
				s = w;
				need++;
			}
		}
		return true;
	}

	public static void main(String[] args) {

		Scanner scanner = new Scanner(System.in);
		while (true) {
			int n = scanner.nextInt();
			int m = scanner.nextInt();
			if (n == 0 && m == 0)
				break;
			int[] book = new int[m];
			int r = 0;
			for (int i = 0; i < m; i++) {
				book[i] = scanner.nextInt();
				r += book[i];
			}
			int l = r / n;

			while (r - l > 1) {
				int mid = (l + r) / 2;
				if (f(mid, book, n, m)) {
					r = mid;
				} else {
					l = mid;
				}
			}
			System.out.println(f(l, book, n, m) ? l : r);
		}

	}
}
