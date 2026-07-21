import java.util.Scanner;
import java.util.stream.IntStream;

public class Main {

	public static void main(String[] args) {
		try (Scanner scanner = new Scanner(System.in)) {
			int k = scanner.nextInt(), n = scanner.nextInt();
			int[] a = new int[n];
			IntStream.range(0, n).forEach(i -> a[i] = scanner.nextInt());
			System.out.println(k - IntStream.range(0, n).map(i -> (i == 0) ? a[0] + k - a[n - 1] : a[i] - a[i - 1])
					.max().getAsInt());
		}
	}
}
