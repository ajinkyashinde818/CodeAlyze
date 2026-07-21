import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {

	@SuppressWarnings("resource")
	public static void main(String args[]) {
		Scanner scanner = new Scanner(System.in);
		int d = scanner.nextInt();
		int g = scanner.nextInt();
		int p[] = new int[d];
		int c[] = new int[d];

		for (int i = 0; i < d; i++) {
			p[i] = scanner.nextInt();
			c[i] = scanner.nextInt() + (i + 1) * 100 * p[i];
		}

		int min = 1000000000;
		for (int i = 0; i < Math.pow(2, d); i++) {
			int scr = 0;
			int cnt = 0;
			List<Integer> list = new ArrayList<>();
			for (int j = 0; j < d; j++) {
				if ((i >> j & 1) == 1) {
					scr += c[j];
					cnt += p[j];
					list.add(j);
				}
			}
			if (scr >= g && cnt < min) {
				min = cnt;
				continue;
			}
			for (int j = d - 1; j >= 0; j--) {
				if (!list.contains(j)) {
					for (int k = 0; k < p[j]; k++) {
						scr += (j + 1) * 100;
						cnt++;
						if (scr >= g && cnt < min)
							min = cnt;
					}
				}
			}

		}

		System.out.println(min);

	}
}
