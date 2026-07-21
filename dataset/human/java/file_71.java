import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		try (Scanner s = new Scanner(System.in)) {
			final int N = s.nextInt();

			long ret = 0;
			long min = Long.MAX_VALUE;
			boolean plus = true;
			for (int i = 0; i < N; i++) {
				long a = s.nextLong();
				if (a < 0) {
					plus = !plus;
				}

				ret += Math.abs(a);
				min = Math.min(min, Math.abs(a));
			}
			if (!plus) {
				ret = ret - min * 2;
			}
			System.out.println(ret);
		}
	}
}
