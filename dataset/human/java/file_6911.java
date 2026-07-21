import java.util.*;

class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int K = sc.nextInt();
		int N = sc.nextInt();
		int[] A = new int[N];
		for(int i=0; i < N; i++) {
			A[i] = sc.nextInt();
		}
		int[] B = new int[N];
		for(int i=0; i < N-1; i++) {
			B[i] = A[i + 1] - A[i];
		}
		B[N-1] = A[0] + (K - A[N-1]);
		int sumB = 0;
		for(int i=0; i < N; i++) {
			sumB += B[i];
		}
		
		
		int maxL = 0;
		
		for(int i = 0; i < N; i++) {
			maxL = Math.max(maxL, B[i]);
		}


		System.out.println(sumB - maxL);

	}


}
