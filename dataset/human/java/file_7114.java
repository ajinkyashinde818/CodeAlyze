import java.util.*;
public class Main {
	public static void main(String args[]) {
		Scanner sc = new Scanner(System.in);
		int K = sc.nextInt();
		int N = sc.nextInt();
		int A[] = new int[N];
		int max = 0;
		for(int i = 0; i < N; i++) {
			A[i] = sc.nextInt();
			if(i > 0) {
				max = Math.max(A[i] - A[i - 1], max);
			}
		}
		max = Math.max(K - A[N - 1] + A[0], max);
		System.out.println(K - max);
	}
}
