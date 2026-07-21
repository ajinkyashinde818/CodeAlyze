import java.util.Arrays;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int k = sc.nextInt();
		int n = sc.nextInt();
		int a[] = new int[n];
		int d[] = new int[n];

		for (int i = 0; i < n; i++) {
			a[i] = sc.nextInt();
		}

		for (int i = 1; i < n; i++) {
			d[i] = a[i] - a[i - 1];
		}

		d[0] = a[0] + (k - a[n - 1]);

		Arrays.sort(d);

		int answer = 0;
		for (int i = 0; i < n - 1; i++) {
			answer += d[i];
		}

		System.out.println(answer);
		sc.close();

	}
}
