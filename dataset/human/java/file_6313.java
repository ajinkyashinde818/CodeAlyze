import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		try (Scanner scanner = new Scanner(System.in)) {
			int maxValue = scanner.nextInt();
			int S = scanner.nextInt();

			int cnt = 0;
			for (int x = 0; x <= maxValue; x++) {
				for (int y = 0; y <= maxValue; y++) {
					int z = S - x - y;
					if (z >= 0 && z <= maxValue) cnt++;
				}
			}
			System.out.println(cnt);

		}
	}
}
