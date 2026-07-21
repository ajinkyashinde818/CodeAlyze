import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int K = sc.nextInt();
		int N = sc.nextInt();
		int[] A = new int[N];
		for(int i = 0; i < N; i++) {
			A[i] = sc.nextInt();
		}
		int longDistance = 0;
		for(int i = 0; i < N; i++) {
			int tmp = 0;
			if(i == N-1) {
				tmp = Math.abs(A[i]-(A[0]+K));
			} else {
				tmp = Math.abs(A[i]-A[i+1]);
			}

			if(tmp > longDistance) {
				longDistance = tmp;
			}
		}
		System.out.println(K-longDistance);
	}
}
