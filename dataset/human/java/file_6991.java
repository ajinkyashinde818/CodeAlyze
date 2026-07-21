import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		int K = 0;
		int N = 0;
		Scanner sc = new Scanner(System.in);
		K = Integer.parseInt(sc.next());
		N = Integer.parseInt(sc.next());
		int A[] = new int[N];
		int i;
		for (i = 0; i < N; i++) {
			A[i] = Integer.parseInt(sc.next());
		}
		int max = 0;
		for (i = 0; i < N - 1; i++) {
			if (max < A[i + 1] - A[i]) {
				max = A[i + 1] - A[i];
			}
		}
		if (max < A[0] + K - A[N - 1]) {
			max = A[0] + K - A[N - 1];
		}
		System.out.println(K - max);
		sc.close();

	}

}
