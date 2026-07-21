import java.util.Arrays;
import java.util.Collections;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		long sum = 0;
		long x = 0;
		long min = (long)Math.pow(10, 15);
		int N = scan.nextInt();
		Long[] a = new Long[N];
		for(int i = 0; i < N; i++) {
			a[i] = scan.nextLong();
			sum += a[i];
		}
		for(int i = 0; i < N - 1; i++) {
			x += a[i];
			min = (long)Math.min(min, (long)Math.abs(sum - 2 * x));
		}
		System.out.println(min);
		scan.close();

	}

}
