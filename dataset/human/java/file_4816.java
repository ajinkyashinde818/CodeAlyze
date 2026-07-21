import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		long n = sc.nextLong();
		sc.close();

		long count = 0;
		if (n % 2 == 0) {
			for (int i = 0; i < 25; i++) {
				count += (n / (long)(Math.pow(5, i + 1) * 2));
			}
		}
		System.out.println(count);
	}
}
