import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		long n = sc.nextLong();
		long ans = 0;

		if ((n % 2) == 0) {
			long t = n / 2;
			for (int i = 1; i < 50; i++) {
				ans += t / (long) Math.pow(5, i);
			}
		}

		System.out.println(ans);

		sc.close();
	}

}
