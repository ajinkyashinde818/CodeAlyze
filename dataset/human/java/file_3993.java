import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int[] A = new int[N + 1];
		int[] B = new int[N + 1];
		int[] C = new int[N];
		int sum = 0;
		int target = -1;
		int add = 0;

		for (int i = 1; i < N + 1; i++) {
			A[i] = sc.nextInt();
		}
		for (int i = 1; i < N + 1; i++) {
			B[i] = sc.nextInt();
		}
		for (int i = 1; i < N; i++) {
			C[i] = sc.nextInt();
		}

		for (int i = 1; i < N + 1; i++) {
			sum+=B[A[i]];
			//addできるか
			if (A[i] == target) {
				sum+=add;
				target = -1;
			}

			//C確認
			if (A[i] < C.length) {
				target = A[i] + 1;
				add = C[A[i]];
			}else {
				target = -1;
			}

		}

		System.out.println(sum);
	}

}
