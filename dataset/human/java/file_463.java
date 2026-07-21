import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int N = scan.nextInt();
		int R = scan.nextInt();

		if(N >= 10) {
			System.out.println(R);
		}else {
			System.out.println(R + 100 * (10-N));
		}
	}
}
