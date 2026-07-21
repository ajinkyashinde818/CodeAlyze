import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		long K = sc.nextLong();
		long S = sc.nextLong();
		long count = 0;

		for (int i = 0; i <= K; i++) {
			for (int j = 0; j <= K; j++) {
				if (S - i - j <= K && 0 <= S - i - j) {
					count++;
				}
			}
		}
		System.out.println(count);
	}
}
