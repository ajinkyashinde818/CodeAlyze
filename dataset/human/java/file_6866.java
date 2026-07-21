import java.util.Arrays;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		// TODO 自動生成されたメソッド・スタブ

		Scanner sc = new Scanner(System.in);

		//1周の距離
		int K = sc.nextInt();
		//家の数
		int N = sc.nextInt();

		//家の距離
		int A[] = new int[N];
		int B[] = new int[N];

		int sum = 0;
		//家の数分繰り返す
		for (int i = 0; i < N; i++) {
			A[i] = sc.nextInt();

		}

		//
		for (int i = 0; i < N; i++) {
			if (i == 0) {
				B[i] = K - A[N - 1] + A[i];
			} else {
				B[i] = A[i] - A[i - 1];
			}
		}
		Arrays.sort(B);

		for (int i = 0; i < N - 1; i++) {
			sum += B[i];

		}
		System.out.println(sum);
		sc.close();
	}

}
