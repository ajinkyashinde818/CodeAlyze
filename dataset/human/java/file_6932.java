import java.util.Scanner;


public class Main {
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int K = sc.nextInt();
		int N = sc.nextInt();
		int[] A = new int[N];
		for (int i = 0; i < N ; i++) A[i] = sc.nextInt();
		int max = (K - A[N-1]) + A[0];
		for (int i = 1; i < N; i++) {
				int m = A[i] - A[i-1];
				if (max < m) max = m;
		}
		System.out.println(K - max);
	}
}
