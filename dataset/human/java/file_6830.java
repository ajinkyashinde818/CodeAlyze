import java.util.Scanner;

public class Main {

	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);

		String[] t = sc.nextLine().split(" ");
		int n = Integer.parseInt(t[0]);
		int k = Integer.parseInt(t[1]);

		String[] x = sc.nextLine().split(" ");
		int[] list = new int[k];
		int max = 0;

		for(int i = 0; i < k; i++) {
			list[i] = Integer.parseInt(x[i]);
		}

		for(int i = 0; i < k; i++) {
			if(i != 0 && i != k-1) {

				max = Math.max(max, Math.max(list[i] - list[i - 1], list[i + 1] - list[i]));
			}
		}
		System.out.println(n - Math.max(max, n - list[k - 1] + list[0]) );
	}
}
