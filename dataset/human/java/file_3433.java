import java.util.Scanner;

public class Main {
	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();

		if (n / 10 == 9 || n % 10 == 9) {
			System.out.print("Yes");
		} else {
			System.out.print("No");
		}
	}
}
