import java.util.Scanner;

public class Main {

	public static long[] nums;

	public static void main(String[] args) {

		Scanner scan = new Scanner(System.in);
		int N = scan.nextInt();
		boolean flag1 = false;
		boolean flag2 = false;

		for (int i = 0; i < N; i++) {
			int D1 = scan.nextInt();
			int D2 = scan.nextInt();

			if (D1 == D2 && flag1 && flag2) {
				System.out.println("Yes");
				System.exit(0);
			}

			flag1 = flag2;
			flag2 = D1 == D2;
		}

		System.out.println("No");
	}
}
