import java.util.Scanner;
public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		long a = sc.nextLong();
		long b = sc.nextLong();
		System.out.println(mini(a,b));
	}
	public static long mini(long a, long b) {
		long temp;
		long c = a*b;
		while((temp = a%b) != 0) {
			a = b;
			b = temp;
		}
		return c/b;
	}
}
