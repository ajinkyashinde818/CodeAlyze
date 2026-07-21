import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		int x = sc.nextInt();
		String ans = "";

		if (x < 1200) {
			ans ="ABC";
		} else {
			ans = "ARC";
		}

		System.out.println( ans );
	}
}
