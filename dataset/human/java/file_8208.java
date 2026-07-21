import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		int a = sc.nextInt();
		int b = sc.nextInt();

		// aとbの最小公倍数を求める
		long lcm = calcLcm(a, b);
		System.out.println(lcm);

		sc.close();
	}

	static long calcLcm(int a, int b) {
		int max = Math.max(a, b);
		int min = Math.min(a, b);
		long product = 1l * max * min;

		if (min == 0)
			return max;

		int temp;
		while ((temp = max % min) != 0) {
			max = min;
			min = temp;
		}

		return product / min;
	}

}
