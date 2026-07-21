import java.util.Scanner;

public class Main {
	static Scanner scn = new Scanner(System.in);

	public static void main(String[] args) {
		int k = scn.nextInt(), n = scn.nextInt(), temp = 0, sum = 0;
		int[] arr = new int[n + 1];
		for (int i = 1; i < n + 1; i++) {
			temp = scn.nextInt();
			arr[i] = temp - sum;
			sum += arr[i];
		}
		int min = temp - arr[1];
		for (int i = 2; i <= n - 1; i++) {
			min = Integer.min(min, Integer.min(k - arr[i + 1], k - arr[i - 1]));
		}
		System.out.println(min);
	}
}
