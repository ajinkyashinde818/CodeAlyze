import java.util.Scanner;

public class Main {
	public static void main(String args[]) {
		Scanner scan = new Scanner(System.in);
		int K = scan.nextInt();
		int N = scan.nextInt();
		int A[] = new int[N];
		for (int i = 0; i < N; i++) {
			A[i] = scan.nextInt();
		}
		int Max = 0;
		for (int i = 1; i < N; i++) {
			Max = Math.max(A[i] - A[i-1], Max);
		}
		Max = Math.max( K - A[N-1] + A[0], Max);

		System.out.println(K - Max);
	}
}
