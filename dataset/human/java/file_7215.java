import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		String str[] = br.readLine().split(" ");

		int k = Integer.parseInt(str[0]);
		int n = Integer.parseInt(str[1]);

		int a[] = new int[n];

		str = br.readLine().split(" ");

		for (int i = 0; i < n; i++) {
			a[i] = Integer.parseInt(str[i]);
		}

		int min = k - Math.abs(k - Math.abs(a[0] - a[n - 1]));

		for (int i = 0; i < n - 1; i++) {
			min = Math.min(min, k - Math.abs(a[i] - a[i + 1]));
		}

		System.out.println(min);
	}
}
