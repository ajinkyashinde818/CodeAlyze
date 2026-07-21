import java.util.Arrays;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {

		Scanner scan = new Scanner(System.in);

		int K = scan.nextInt();
		int N = scan.nextInt();
		int[] A = new int[N];
		for (int i = 0; i < N; i++) {
			A[i] = scan.nextInt();
		}

		Arrays.sort(A);

		int max = K - A[N-1] + A[0];

		for (int i = 1; i < N; i++) {
			if (A[i]-A[i-1] > max) {
				max = A[i]-A[i-1];
			}
		}

		System.out.println(K-max);

	}

}
