import java.util.Scanner;

public class Main {
	public static void main(String[] args) throws Exception {
		Scanner sc = new Scanner(System.in);
		long a = sc.nextLong();
		long b = sc.nextLong();
		long c = sc.nextLong();
		sc.close();

		if (a + b + 1 >= c) {
			System.out.println(b + c);
		} else {
			System.out.println(b + a + b + 1);
		}
	}
}
