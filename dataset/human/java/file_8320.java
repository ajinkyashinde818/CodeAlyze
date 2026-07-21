import java.util.*;
public class Main {

	public static long gcd(int a, int b) {
		return b == 0 ? a: gcd(b, a % b);
	}
	
	public static long lcm(int a, int b) {
		return a / gcd(a, b) * b;
	}
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		System.out.println(lcm(sc.nextInt(), sc.nextInt()));

	}

}
