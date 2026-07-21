import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int K = sc.nextInt();
		int N = sc.nextInt();
		int[] A = new int[N];
		for (int i = 0; i < N; i++) {
			A[i] = sc.nextInt();
		}
		sc.close();

		int max = 0;
		for ( int i = 0 ; i < N - 1 ; i++ ) {
			max = Math.max(max, A[i+1] - A[i]);
		}
		max = Math.max(max, K - A[N-1] + A[0]);

		System.out.println(K - max);
	}
}
