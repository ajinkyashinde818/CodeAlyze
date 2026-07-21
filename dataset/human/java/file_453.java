import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		try (Scanner sc = new Scanner(System.in)) {
			int N = sc.nextInt();
			int R = sc.nextInt();
			if (N >= 10) {
				System.out.print(R);
			} else {
				System.out.print(R + 100 * (10 - N));
			}
		}
	}

}
