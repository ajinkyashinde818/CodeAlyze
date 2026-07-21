import java.util.Scanner;

public class Main {

	public static void main(String[] args) {

		try (Scanner sc = new Scanner(System.in)) {

			long N = sc.nextLong();

			if (N % 2 == 1) {
				System.out.println(0);
				return;
			}

			long total = 0;

			long div = 1;
			while (N / div >= 5) {
				div *= 5;
				total += (N / (div * 2));
			}

			System.out.println(total);

		}
	}

}
