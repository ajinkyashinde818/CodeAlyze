import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		int n = Integer.parseInt(br.readLine());

		long a[] = new long[n];

		String str[] = br.readLine().split(" ");
		for (int i = 0; i < n; i++) {
			a[i] = Long.parseLong(str[i]);
		}

		long s[] = new long[n];
		s[0] = a[0];

		for (int i = 1; i < n; i++) {
			s[i] = s[i - 1] + a[i];
		}

		long ans = Long.MAX_VALUE;
		for (int i = 0; i < n - 1; i++) {
			long left = s[i];
			long right = s[n - 1] - s[i];

			long abs = Math.abs(left - right);
			ans = Math.min(ans, abs);
		}
		System.out.println(ans);
	}
}
