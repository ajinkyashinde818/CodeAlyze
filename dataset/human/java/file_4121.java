import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int n = scan.nextInt();
		int[] section = new int[n];
		int[] happy_B = new int[n];
		int[] happy_C = new int[n - 1];
		int goukei = 0;
		for (int i = 0; i < n; i++) {
			section[i] = scan.nextInt();
		}
		for (int i = 0; i < n; i++) {
			happy_B[i] = scan.nextInt();
		}
		for (int i = 0; i < n - 1; i++) {
			happy_C[i] = scan.nextInt();
		}
		goukei += happy_B[section[0] - 1];
		for (int i = 1; i < n; i++) {
			if (section[i] == section[i - 1] + 1) {
				goukei += happy_B[section[i] - 1] + happy_C[section[i - 1] - 1];
			} else {
				goukei += happy_B[section[i] - 1];
			}
		}
		System.out.println(goukei);

	}
}
