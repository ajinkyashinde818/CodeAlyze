import java.util.Scanner;

public class Main {

	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);

		int a = sc.nextInt();
		int b = sc.nextInt();
		int k = sc.nextInt();
		int num = 0;
		int count = 0;

		for (int i = Math.min(a, b); i > 0; i--) {
			if (a % i == 0 && b % i == 0) {
				count++;
			}
			if (count == k) {
				num = i;
				break;
			}
		}

		System.out.print(num);
	}
}
