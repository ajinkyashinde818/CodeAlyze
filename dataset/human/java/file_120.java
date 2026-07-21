import java.util.Arrays;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = Integer.parseInt(sc.next());
		long[] a = new long[n];
		for (int i = 0; i < n; i++) {
			a[i] = sc.nextInt();
		}
		long sum = 0;
		int negative = (int) Arrays.stream(a).filter(i -> i < 0).count();
		if (negative % 2 == 0) {
			sum = Arrays.stream(a).map(i -> Math.abs(i)).sum();
		} else {
			int min = (int) Arrays.stream(a).map(i -> Math.abs(i)).min().getAsLong();
			sum = Arrays.stream(a).map(i -> Math.abs(i)).sum() - min * 2;
		}
		System.out.println(sum);
	}

}
