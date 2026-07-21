import java.util.Scanner;

public class Main {
	public static void main(String[] args) throws Exception {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int R = sc.nextInt();
		if (N < 10) {
			System.out.println(R + 100 * (10 - N));
		} else {
			System.out.println(R);
		}
	}
}
