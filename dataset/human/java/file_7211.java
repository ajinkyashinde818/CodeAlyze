import java.util.Arrays;
import java.util.Scanner;

public class Main {
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int k = sc.nextInt();
		int n = sc.nextInt();
		int[] a = new int[n];
		Arrays.setAll(a, i -> sc.nextInt());

		int max = a[0] + k - a[n - 1];
		for (int i = 1; i < n; i++) {
			max = Math.max(max, a[i] - a[i - 1]);
		}
		int ans = k - max;
		System.out.println(ans);
		sc.close();
	}
}
