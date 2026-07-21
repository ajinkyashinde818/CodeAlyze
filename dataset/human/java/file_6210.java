import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		int k = scanner.nextInt();
		int s = scanner.nextInt();
		scanner.close();

		int count = 0;

		for (int x = 0; x <= k; x++) {
			for (int y = 0; y <= k; y++) {
				int z = 0;
				if(x + y < s && s - (x + y) <= k) {
					z = s - (x + y);
				}
				if (x + y + z == s) {
					// System.out.printf("%d, %d, %d\n", x, y, z);
					count++;
				}
			}
		}

		System.out.println(count);

	}

}
