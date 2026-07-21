import java.util.Scanner;

public class Main {

	static Main instance = new Main();

	public static void main(String[] args) {

		Scanner scan = new Scanner(System.in);

		//入力値
		int K = scan.nextInt();
		int N = scan.nextInt();
		int[] A = new int[N];

		for (int i = 0; i < N; i++) {
			A[i] = scan.nextInt();
		}

		int maxDif = A[0] + K - A[N-1];

		for (int i = 0; i < N - 1; i++) {
			if (A[i+1] - A[i] > maxDif) {
				maxDif = A[i+1] - A[i];
			}
		}

		int length = K-maxDif;

		System.out.println(length);
	}
}
