import java.util.Scanner;

//AtCoder Beginner Contest 148
//C	Snack
public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		long A = Long.parseLong(sc.next());
		long B = Long.parseLong(sc.next());
		sc.close();

		// ユークリッドの互除法
		long a = A;
		long b = B;
		if (A < B) {
			a = B;
			b = A;
		}
		long r = a % b;
		while (r != 0) {
			a = b;
			b = r;
			r = a % b;
		}
		long x = A * B;
		System.out.println(x / b);
	}
}
