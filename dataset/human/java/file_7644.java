import java.util.Scanner;

public class Main {

	public static void main(String[] args) {

		Scanner scan = new Scanner(System.in);

		int N = scan.nextInt();
		long K = scan.nextLong();
		int[] A = new int[N + 1];
		int[] counts = new int[N + 1];
		int count = 0;
		int loop = 0;

		for (int i = 1; i <= N; i++) {
			A[i] = scan.nextInt();
			counts[i] = -1;
		}

		int current = 1;
		while (true) {
			if (count == K) {
				System.out.println(current);
				System.exit(0);
			}
			if (counts[current] != -1) {
				loop = count - counts[current];
				break;
			}
			counts[current] = count;
			current = A[current];
			count++;
		}

		K -= count;
		long num = K % loop;

		for (int i = 0; i < num; i++) {
			current = A[current];
		}

		System.out.println(current);
 	}
}
