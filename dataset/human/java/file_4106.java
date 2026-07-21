import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner in = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
		int n = in.nextInt();
		int[] a = new int[n];
		int[] b = new int[n];
		int[] c = new int[n];
		for (int i = 0; i < n; i++)
			a[i] = in.nextInt() - 1;
		for (int i = 0; i < n; i++)
			b[i] = in.nextInt();
		for (int i = 0; i < n-1; i++)
			c[i] = in.nextInt();
		System.out.println(solve(n, a, b, c));
		in.close();
	}

	private static int solve(int n, int[] a, int[] b, int[] c) {
		int r = 0;
		for (int i = 0; i < n; i++) {
			r += b[a[i]];
			if (i < n - 1)
				if (a[i] + 1 == a[i + 1])
					r += c[a[i]];
		}
		return r;
	}
}
