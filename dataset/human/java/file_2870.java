import java.util.Scanner;
import java.util.StringTokenizer;

public class Main {

	public static void main(String[] args) {

		Scanner scanner = new Scanner(System.in);
		while (scanner.hasNext()) {
			StringTokenizer tokenizer = new StringTokenizer(scanner.nextLine()
					);
			int[] num = new int[8];
			for (int i = 0; i < 8; i++) {
				num[i] = Integer.parseInt(tokenizer.nextToken());
			}
			int[] a = { 1, 2, 1, 2, 1, 4, 1, 4 };
			int[] b = { 0, 2, 6, 4, 1, 3, 7, 5 };
			int min = Integer.MAX_VALUE;
			int resut = 0;
			for (int i = 0; i < 8; i++) {
				int sum = 0;
				for (int j = 0; j < 8; j++) {
					int c = a[(j + b[i]) % 8];
					sum += c - num[j] < 0 ? 0 : c - num[j];
				}
				if (min > sum) {
					min = sum;
					resut = i;
				}
			}
			for (int i = 0; i < 8; i++) {
				if (i != 0) {
					System.out.print(" ");
				}
				System.out.print(a[(i + b[resut]) % 8]);
			}
			System.out.println();
		}

	}
}
