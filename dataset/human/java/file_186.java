import java.util.Arrays;
import java.util.Scanner;

public class Main {
	void run() {
		Scanner scan = new Scanner(System.in);
		int n = scan.nextInt();
//		long[] a = new long[n];
		long sum = 0;
		long min = Long.MAX_VALUE;
		int c = 0;
		for (int i = 0; i < n; i++) {
			long a = scan.nextLong();
			if (a < 0) {
				c++;
				a *= -1;
			}
			min = Math.min(a, min);
			sum += a;
		}
		if (c % 2 == 0)
			System.out.println(sum);
		else
			System.out.println(sum - (min * 2));
	}

	int gcd (int a, int b) {
		int temp;
		while((temp = a%b)!=0) {
			a = b;
			b = temp;
		}
		return b;
	}

    public static void main(String[] args) {
    	new Main().run();
    }
}
