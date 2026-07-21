import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);

		long k = sc.nextLong();

		int n = sc.nextInt();

		List<Long> list = new ArrayList<Long>();

		for (long i = 0; i < n; i++) {
			list.add(sc.nextLong());
		}

		list.add(k);

		long totalA = 0;
		long maxLength = 0;
		int point = 0;

		for (int num = 0; num < list.size() - 1; num++) {
			Long a = list.get(num);
			Long b = list.get(num + 1);

			if (maxLength <= (b - a)) {
				maxLength = b - a;
				point = num + 1;
			}
		}

		if (maxLength <= k - list.get(list.size() - 2) + list.get(0)) {
			maxLength = k - list.get(list.size() - 2) + list.get(0);
			point = 0;
		}

		for (int num = point; num < list.size() - 1; num++) {
			Long a = list.get(num);
			Long b = list.get(num + 1);

			if (point == 0 && num + 1 == n) {
				break;
			}

			totalA += b - a;
		}

		if (0 < totalA && list.get(0) != 0 && 1 < point) {
			totalA += list.get(0);
		}

		for (int num = 0; num < point - 1; num++) {

			if (num + 1 == n) {
				break;
			}

			Long a = list.get(num);
			Long b = list.get(num + 1);

			totalA += b - a;
		}

		System.out.println(totalA);

	}
}
