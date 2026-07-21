import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.math.BigInteger;
import java.util.Scanner;

public class Main {

	private static final boolean TEST = false;

	public static void main(String[] args) {
		Scanner in = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
		int n = in.nextInt();
		int[] a = new int[n];
		for (int i = 0; i < n; i++) {
			a[i] = in.nextInt();
		}
		System.out.println(solve(a));
		in.close();
	}

	private static long solve(int[] a) {
		int mi = 0;
		for (int i = 1; i < a.length; i++)
			if (Math.abs(a[mi]) > Math.abs(a[i]))
				mi = i;

		long ans = 0;
		if (a[mi] == 0) {
			for (int i = 0; i < a.length; i++)
				ans += Math.abs(a[i]);
			return ans;
		}

		for (int i = 0; i < mi; i++)
			if (a[i] < 0) {
				ans -= a[i];
				a[i + 1] *= -1;
			} else
				ans += a[i];
		for (int i = a.length - 1; i > mi; i--)
			if (a[i] < 0) {
				ans -= a[i];
				a[i - 1] *= -1;
			} else
				ans += a[i];
		ans += a[mi];
		return ans;
	}
}
