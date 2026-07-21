import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		long n = Long.parseLong(br.readLine());
		br.close();

		if (n % 2 == 1) {
			System.out.println(0);
		} else {
			long ans = 0;
			for (long b = 10; b <= n; b *= 5) {
				ans += n / b;
			}
			System.out.println(ans);
		}
	}
}
