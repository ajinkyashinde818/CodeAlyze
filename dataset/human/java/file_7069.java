import java.util.Scanner;

public class Main {
	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);
		int k = sc.nextInt();
		int n = sc.nextInt();
		int[] a_n = new int[n];

		for (int i = 0; i < n; i++) {
			a_n[i] = sc.nextInt();
		}

		sc.close();

		int maxDistance = 0;
		int tmp = 0;
		for (int i = 0; i < n - 1; i++) {
			tmp = a_n[i + 1] - a_n[i];
			maxDistance = Math.max(tmp, maxDistance);
		}

		maxDistance = Math.max(maxDistance, (k - a_n[n - 1] + a_n[0]));

		System.out.println(k - maxDistance);
	}
}
