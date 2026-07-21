import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		// 入力値の取得
		long A = sc.nextLong();
		long B = sc.nextLong();

		long answer = A * B / calcGcd(A, B);
		System.out.println(answer);

		sc.close();
	}

	static long calcGcd(long m, long n) {
		if (m < n) {
			long tmp = m;
			m = n;
			n = tmp;
		}
		long remainder = 0;
		while ((remainder = m % n) != 0) {
			m = n;
			n = remainder;
		}
		return n;
	}
}
