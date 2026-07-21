import java.util.Scanner;

public class Main {

	public static void main(String[] args) {

		@SuppressWarnings("resource")
		Scanner scanner = new Scanner(System.in);

		long a = scanner.nextLong();
		long b = scanner.nextLong();

		System.out.println(a * b / gcs(a, b));

	}

	static long gcs(long a, long b) {

		long tmp;
		while ((tmp = a % b) != 0) {
			a = b;
			b = tmp;
		}
		return b;

	}

}
