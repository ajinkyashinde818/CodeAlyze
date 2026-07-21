import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int d = sc.nextInt();
		int g = sc.nextInt();

		int[] p = new int[d];
		int[] c = new int[d];
		for (int i = 0; i < d; i++) {
			p[i] = sc.nextInt();
			c[i] = sc.nextInt();
		}

		int answer = 1000000000;
		for (int i = (1 << d); i >= 0; i--) {
			int count = 0;
			int score = 0;
			for (int j = 0; j < d; j++) {
				if (((i >> j) % 2 == 1)) {
					score += p[j] * (j + 1) * 100;
					score += c[j];
					count += p[j];
				}
			}
			if (score >= g) {
				answer = Math.min(answer, count);
				continue;
			}

			for (int j = d - 1; j >= 0; j--) {
				if (((i >> j) % 2 == 0)) {
					if ((p[j] - 1) * (j + 1) * 100 >= g - score) {
						count += (g - score) / ((j + 1) * 100) + ((g - score) % ((j + 1) * 100) > 0 ? 1 : 0);
						answer = Math.min(answer, count);
					}
					break;
				}
			}
		}

		System.out.println(answer);
	}

}
