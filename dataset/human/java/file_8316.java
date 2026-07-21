import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int a = sc.nextInt();
		int b = sc.nextInt();
		sc.close();
		System.out.println(lcm(a,b));
	}
	/**
	 * lcm 最小公倍数とは「２つ以上の正の整数に共通な倍数のうち最小のもの」
	 * @param a
	 * @param b
	 * @return
	 */
	static long lcm (int a, int b) {
		int temp;
		long c = a;
		c *= b;
		while((temp = a%b)!=0) {
			a = b;
			b = temp;
		}
		return (long)(c/b);
	}
}
