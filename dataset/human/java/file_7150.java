import java.util.*;
import java.lang.*;

class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int k = sc.nextInt();
		int n = sc.nextInt();
		int[] a = new int[n * 2];
		long current = 0;
		for (int i = 0; i < n; i++) {
			a[i] = sc.nextInt();
			a[i + n] = a[i] + k;
			if (i > 0) current += a[i] - a[i - 1];
		}

		long answer = current;
		for (int i = 0; i < n; i++) {
			current -= a[i + 1] - a[i];
			current += a[i + n] - a[i + n - 1];
			answer = Math.min(answer, current);
		}

		System.out.println(answer);
	}
}
