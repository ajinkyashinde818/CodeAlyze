import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		int n = Integer.parseInt(br.readLine());

		int a[] = new int[n];
		int b[] = new int[n];
		int c[] = new int[n - 1];

		String str[] = br.readLine().split(" ");
		for (int i = 0; i < n; i++) {
			a[i] = Integer.parseInt(str[i]);
		}

		str = br.readLine().split(" ");
		for (int i = 0; i < n; i++) {
			b[i] = Integer.parseInt(str[i]);
		}

		str = br.readLine().split(" ");
		for (int i = 0; i < n - 1; i++) {
			c[i] = Integer.parseInt(str[i]);
		}

		int ans = b[a[0] - 1];
		for (int i = 1; i < n; i++) {
			ans += b[a[i] - 1];

			if (a[i - 1] + 1 == a[i]) {
				ans += c[a[i - 1] - 1];
			}
		}

		System.out.println(ans);
	}
}
