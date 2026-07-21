import java.util.Scanner;

public class Main {
	static Scanner scn = new Scanner(System.in);

	public static void main(String[] args) {
		int n = scn.nextInt();
		int DR = scn.nextInt();
		int CR = 0;
		if (n > 10) {
			CR = DR;
		} else {
			CR = DR + 100 * (10 - n);
		}
		System.out.println(CR);
	}
}
