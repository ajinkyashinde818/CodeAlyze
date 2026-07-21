import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		long n = scanner.nextLong();
		if (n % 2 == 1) {
			System.out.println(0);
			return;
		}
		long count = 0;
		while (n > 0) {
			n /= 5;
			count += n / 2;
		}
		System.out.println(count);
	}

}
