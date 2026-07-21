import java.util.Scanner;

public class Main {

	public static void main(String[] args) {

		new Main().run();
	}

	private void run() {
		Scanner scanner = new Scanner(System.in);
		int n = scanner.nextInt();
		while (n-- > 0) {
			int num = Integer.MAX_VALUE;
			int num2 = (1 << 8) - 1;
			long s = Long.parseLong(scanner.next(), 16);
			int x = (int) (s & num) >> 7;
			double y = (s & num2) * Math.pow(2, -7);
			String a = String.valueOf(y).substring(2);
			if (s >Integer.MAX_VALUE)
				System.out.print("-");
			System.out.printf("%d.%s\n", x, a);
		}
	}
}
