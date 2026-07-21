import java.util.Scanner;
import java.util.stream.Stream;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		long[] items = Stream.of(sc.nextLine().split(" ", 0)).mapToLong(Long::parseLong).toArray();
		sc.close();
		Main main = new Main();
		if (items[0] > items[1]) {
			long let = items[0];
			items[0] = items[1];
			items[1] = let;
		}
		long ans = items[0] / main.GCD(items[0], items[1]) * items[1];
		System.out.println(ans);
	}

	public long GCD(long num1, long num2) {
		if (num2 == 0) {
			return num1;
		} else {
			return GCD(num2, num1 % num2);
		}
	}


}
