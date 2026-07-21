import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		// 整数の入力
		long a = sc.nextInt();
		long b = sc.nextInt();
		long x = a * b;

		long tmp = 0;
		if (a < b) {
			tmp = a;
			a = b;
			b = tmp;
		}

		long r = a % b;
		while (r != 0) {
			a = b;
			b = r;
			r = a % b;
		}

		System.out.println(x / b);
	}

}
