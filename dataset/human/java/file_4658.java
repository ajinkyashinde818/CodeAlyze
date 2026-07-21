import java.util.Scanner;

public class Main {
	static int n, m;
	static int book[];

	public static int binarySearch(int low, int high) {
		if (high - low <= 0) {
			return high;
		}
		int mid = (low + high) / 2;
		int shellId = 0;
		int sumWidth = 0;
		for (int i = 0; i < m; i++) {
			if (mid < sumWidth + book[i]) {
				shellId++;
				sumWidth = book[i];
			} else {
				sumWidth += book[i];
			}
		}

		if (n <= shellId) {
			return binarySearch(mid + 1, high);
		} else {
			return binarySearch(low, mid);
		}
	}

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int max;

		while (true) {
			n = sc.nextInt();//tana
			m = sc.nextInt();//kann
			if ((n | m) == 0) {
				break;
			}
			book = new int[m];
			max = 0;
			for (int i = 0; i < m; i++) {
				book[i] = sc.nextInt();
				max = Math.max(max, book[i]);
			}

			System.out.println(binarySearch(max, 1500000));
		}
	}
}
