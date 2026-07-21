import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int M = sc.nextInt();
		int N = sc.nextInt();
		String A[] = new String[M];
		String B[] = new String[N];
		for (int i = 0; i < M; i++) {
			A[i] = sc.next();
		}
		for (int i = 0; i < N; i++) {
			B[i] = sc.next();
		}
		for (int i = 0; i < M - N + 1; i++) {
			for (int k = 0; k < M - N + 1; k++) {
				boolean b = Main.check(A, B, i, k, N);
				if (b == true) {
					System.out.println("Yes");
					return;
				}
			}
		}
		System.out.println("No");
		return;
	}

	public static boolean check(String A[], String B[], int startline, int startposition, int N) {
		for (int i=0;i<N;i++ ) {
			for (int j =0;j<N;j++) {
				if (A[i+startline].charAt(startposition+j)!=B[i].charAt(j)) {
					return false;
				}
			}
		}
		return true;
	}
}
