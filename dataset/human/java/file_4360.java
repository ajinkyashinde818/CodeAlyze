import java.util.Scanner;

public class Main
{
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		int N = scanner.nextInt();
		int A[] = new int[N];
		int B[] = new int[N];
		int C[] = new int[N - 1];
		int sum = 0;
		int x = 51;
		int y = 0;
		for (int i  = 0; i < N; i++) {
			A[i] = scanner.nextInt();
		}

		for (int i  = 0; i < N; i++) {
			B[i] = scanner.nextInt();
		}

		for (int i  = 0; i < N - 1; i++) {
			C[i] = scanner.nextInt();
		}
		/*
		for (int k = 0; k < N; k++) {
			System.out.println(A[k]);
		}
		for (int k = 0; k < N; k++) {
			System.out.println(B[k]);
		}
		for (int k = 0; k < N-1; k++) {
			System.out.println(C[k]);
		}*/
		
		for (int j = 0; j < N; j++) {
			y = A[j];
			sum += B[y - 1];
			if (y - 1 == x) {
				sum += C[x - 1];
			}
			x = A[j];
		}
		System.out.println(sum);
	}
}
