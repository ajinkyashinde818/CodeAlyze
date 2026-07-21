import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		try (Scanner sc = new Scanner(System.in)) {
			// 整数の入力
			long a = sc.nextLong();
			long b = sc.nextLong();

			long min = a < b ? a : b;
			long max = a > b ? a : b;

			for (long i = 1; i <= max; i++) {
				if (min * i % max == 0) {
					System.out.println(min * i);
					break;
				}
			}
		}
	}
}
