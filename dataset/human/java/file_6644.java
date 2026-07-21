import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String[] sa = br.readLine().split(" ");
		int n = Integer.parseInt(sa[0]);
		sa = br.readLine().split(" ");
		int[] a = new int[n];
		for (int i = 0; i < n; i++) {
			a[i] = Integer.parseInt(sa[i]);
		}
		br.close();

		long one = (long) n * (n + 1) / 2;
		long sum = 0;
		for (int i = 0; i < n; i++) {
			sum += a[i];
		}
		if (sum % one != 0) {
			System.out.println("NO");
			return;
		}

		int[] b = new int[n];
		for (int i = 0; i < n - 1; i++) {
			b[i] = a[i + 1] - a[i];
		}
		b[n - 1] = a[0] - a[n - 1];

		long t = sum / one;
		for (int i = 0; i < n; i++) {
			b[i] -= t;
			if (b[i] > 0) {
				System.out.println("NO");
				return;
			}
			b[i] *= -1;
			if (b[i] % n != 0) {
				System.out.println("NO");
				return;
			}
		}
		System.out.println("YES");
	}
}
