import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		// 数値
		int n1 = sc.nextInt();
		int n2 = sc.nextInt();

		if (n1 >= 10) {
			System.out.println(n2);
		} else {
			System.out.println(n2 + 100 * (10 - n1));
		}
	}
}
