import java.util.*;
public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int K = sc.nextInt();
		int N = sc.nextInt();
		int[] A = new int[N];
		Arrays.setAll(A, i -> sc.nextInt());
		int max = A[0] + K - A[N-1];
		for(int i = 1; i < N; i++) {
			max = Math.max(max, A[i] - A[i-1]);
		}
		System.out.println(K - max);
	}

}
