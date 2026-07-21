import java.util.Scanner;

public class Main {

	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);
		int k = sc.nextInt();
		int s = sc.nextInt();
		int count = 0;

		for (int x = Math.max(0, s - 2 * k); x <= k; x++) {
			for (int y = Math.max(0, s - k - x); y <= Math.min(k, s - x); y++) {
				//int z = s - x - y;
				//System.out.println(x + "," + y + "," + z);
				count++;
			}
		}
		System.out.println(count);
	}
}
