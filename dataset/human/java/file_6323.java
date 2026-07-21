import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		try (Scanner sc = new Scanner(System.in)) {

			int k = sc.nextInt();
			int s = sc.nextInt();
			int sum = 0;

			int count = 0;
			for (int i = 0; i <= k; i++) {
				for (int j = 0; j <= k; j++) {
					sum = s - (i + j);
					if (sum >= 0 && sum <= k) {
						count++;
					}
				}
			}

			System.out.println(count);
		}
	}

}
