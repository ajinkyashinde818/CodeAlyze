import java.util.*;
public class Main {

	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);
		int K = sc.nextInt();
		int N = sc.nextInt();
		int max = 0;
		int[] A = new int[N];
		A[0] = sc.nextInt();
		for (int i = 1; i < N; i++) {
			A[i] = sc.nextInt();
			if (A[i] - A[i-1] > max) {
				max = A[i]-A[i-1];
			}
		}
		if (K-A[N-1]+A[0] > max) {
			max = K - A[N-1] + A[0];
		} 
		System.out.println(K-max);
	}
}
