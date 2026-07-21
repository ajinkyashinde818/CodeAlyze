import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class Main {
	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		String str[] = br.readLine().split(" ");

		int d = Integer.parseInt(str[0]);
		int g = Integer.parseInt(str[1]);

		int p[] = new int[d];
		int c[] = new int[d];

		for (int i = 0; i < d; i++) {
			str = br.readLine().split(" ");

			p[i] = Integer.parseInt(str[0]);
			c[i] = Integer.parseInt(str[1]);
		}

		int ans = Integer.MAX_VALUE;
		for (int bit = 0; bit < (1 << d); bit++) {
			int problem = 0;
			int point = 0;

			for (int i = 0; i < d; i++) {
				if ((bit & (1 << i)) != 0) {
					problem += p[i];
					point += (1 + i) * 100 * p[i] + c[i];
				}
			}
			if (point >= g) {
				ans = Math.min(ans, problem);
				continue;
			}
			for (int i = 0; i < d; i++) {
				if ((bit & (1 << i)) != 0)
					continue;
				if ((g - point) / ((i + 1) * 100) <= p[i]) {
					problem += (g - point) / ((i + 1) * 100);
					ans = Math.min(ans, problem);
				}
			}
		}
		System.out.println(ans);
	}
}
