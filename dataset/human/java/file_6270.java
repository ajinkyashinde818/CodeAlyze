import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		@SuppressWarnings("resource")
		Scanner scan = new Scanner(System.in);

		int K = scan.nextInt();
		int S = scan.nextInt();

		int count = 0;
		for (int i = 0; i <= K; i++) {
			for (int j = 0; j <= K; j++) {
				if (0 <= S - i - j && S - i - j <= K) {
					count++;
				}
			}
		}
		System.out.println(count);
	}

}
