import java.util.Scanner;

public class Main {

	public static void main(String[] args) {

		Scanner scan = new Scanner(System.in);
		int k = scan.nextInt();
		int n = scan.nextInt();

		int a[] = new int[n];
		for (int i = 0; i < n; i++) {
			a[i] = scan.nextInt();
		}

		int min = a[n - 1] - a[0];
		for (int i = 1; i < n; i++) {
			min = Math.min(min, k - a[i] + a[i - 1]);
		}

		System.out.println(min);

		scan.close();
	}

}
