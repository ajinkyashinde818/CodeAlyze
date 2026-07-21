import java.util.Arrays;
import java.util.Scanner;
import java.util.stream.IntStream;

public class Main {

	public static void main(String[] args) {
		try (Scanner scanner = new Scanner(System.in)) {
			int n = scanner.nextInt();
			long[] a = new long[n];
			int minusCount = (int) IntStream.range(0, n).mapToLong(i -> a[i] = scanner.nextLong()).filter(ai -> ai < 0)
					.count();
			long sum = Arrays.stream(a).map(Math::abs).sum();
			System.out.println(
					(1 == (minusCount & 1)) ? sum - 2 * Arrays.stream(a).map(Math::abs).min().getAsLong() : sum);
		}
	}
}
