import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		long n = sc.nextInt();
		long r = sc.nextInt();
		sc.close();

		long result;
		if (n >= 10) {
			result = r;
		}else {
			result = r + 100 * (10 - n);
		}

		System.out.println(result);
	}
}
