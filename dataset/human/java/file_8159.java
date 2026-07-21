import java.util.Scanner;

public class Main{

	public static void main(String[] args) {

		Scanner scanner = new Scanner(System.in);
		String[] tmp = scanner.nextLine().split(" ");
		long a   = Long.parseLong(tmp[0]);
		long b   = Long.parseLong(tmp[1]);
		long ans = minbai(a, b);


		System.out.println(ans);
	}

	public static long gcd(long x, long y) {

		if(x % y == 0) {

			return y;

		}else {

			return gcd(y, x % y);

		}

	}

	public static long minbai(long x, long y) {

		return x * y / gcd(x,y);

	}
}
