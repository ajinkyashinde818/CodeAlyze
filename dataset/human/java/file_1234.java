import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner scn = new Scanner(System.in);
		int N = scn.nextInt();
		long[] A = new long[N+1];
		for(int i = 0;i < N;i++) {
			A[i+1] = A[i] + scn.nextLong();
		}

		long ans = Long.MAX_VALUE;
		for(int i = 1;i < N;i++) {
			ans = Math.min(ans, Math.abs( A[N] -2* A[i]));
		}
		System.out.println(ans);
	}

}
