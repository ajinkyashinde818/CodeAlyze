import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int K = sc.nextInt();
		long S = sc.nextLong();

		if (S == 1000000000) {
			for (int i = 0; i < K; i++) {
				System.out.print(S + " ");
			}
			for (int i = 0; i < N - K; i++) {
				if (i == N - K - 1) {
					System.out.print("1");
				}else {
					System.out.print("1" + " ");
				}
			}
		}else {
			for (int i = 0; i < K; i++) {
				System.out.print(S + " ");
			}
			for (int i = 0; i < N - K; i++) {
				if (i == N - K - 1) {
					System.out.print(S+1);
				}else {
					System.out.print(S+1 + " ");
				}
			}
		}

	}
}
