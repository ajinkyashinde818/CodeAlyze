import java.util.Arrays;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);

		int k = sc.nextInt();
		int n = sc.nextInt();
		int[] a = new int[n];

		for (int i = 0; i < n; i++) {
			a[i] = sc.nextInt();
		}

		Arrays.sort(a);

		int max = 0;
		for (int i = 0; i < n - 1; i++) {
			max = Math.max(max, a[i + 1] - a[i]);
		}
		max = Math.max(k - a[n - 1] + a[0], max);

		System.out.println(k - max);
	}

}
