import java.util.*;

class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		long a = sc.nextLong();
		long b = sc.nextLong();
		long c = sc.nextLong();
		long res = 0;
		if (a + b >= c - 1) {
			System.out.println(b + c);
			return;
		}
		System.out.println(a + b + 1 + b);
	}
}
