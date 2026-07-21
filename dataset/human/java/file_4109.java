import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		@SuppressWarnings("resource")
		Scanner scanner = new Scanner(System.in);

		int N = scanner.nextInt();

		int[] scannerArrayA = new int[N];
//		int[] scannerArrayB = new int[N];
		int[] scannerArrayC = new int[N];

		int ans = 0;

//		int maxNumber = 0;
//		int number = 0;

		for (int index = 0; index < N; index++) {
//			number = scanner.nextInt();
			scannerArrayA[index] = scanner.nextInt();
		}

		for (int index = 0; index < N; index++) {
//			number = scanner.nextInt();
//			scannerArrayB[index] = scanner.nextInt();
			ans += scanner.nextInt();
		}

		for (int index = 0; index < N-1; index++) {
//			number = scanner.nextInt();
			scannerArrayC[index] = scanner.nextInt();
		}

		int tmp = scannerArrayA[0];

		for(int index = 0; index < N - 1; index++) {
			if((tmp + 1) == scannerArrayA[index + 1]) {
				ans+=scannerArrayC[scannerArrayA[index] - 1];
			}
			tmp = scannerArrayA[index + 1];
		}



		log(ans);
	}

	private static void log(int str) {
		System.out.println(str);
	}

}
