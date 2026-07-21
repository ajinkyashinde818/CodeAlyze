import java.util.Scanner;

public class Main {

	@SuppressWarnings("resource")
	public static void main(String args[]) {
		Scanner scanner = new Scanner(System.in);
		int n = scanner.nextInt();
		int a[] = new int[n];

		long front = 0;
		long back = 0;
		for (int i = 0; i < n; i++) {
			a[i] = scanner.nextInt();
			if (i != n - 1) {
				front += a[i];
			} else {
				back += a[i];
			}
		}

		long min = Math.abs(front - back);
		for (int i = n - 2; i > 0; i--) {
			front -= a[i];
			back += a[i];
			min = Math.min(min, Math.abs(front - back));
		}

		System.out.println(min);

	}
}
