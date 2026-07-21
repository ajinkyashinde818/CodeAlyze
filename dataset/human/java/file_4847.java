import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		long N = in.nextLong();
		long ans = 0;
		long num = 5;
		if (N % 2 == 1) {
			System.out.println(0);
			return;
		}
		while (num <= 1844674407370955161l && (num * 2) <= N) {
			long d = num * 2;
			ans += N / d;
			num *= 5;
		}
		System.out.println(ans);
		in.close();
	}
}
