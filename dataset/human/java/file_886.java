import java.util.Scanner;

public class Main {

	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);

		int n = sc.nextInt();
		int r = sc.nextInt();

		int rate = 0;

		if (n >= 10) {
			rate = r;
		} else {
			rate = r + (100 * (10 - n));
		}

		System.out.println(rate);
	}

}
