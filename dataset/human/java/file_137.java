import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		int n = Integer.parseInt(br.readLine());

		String str[] = br.readLine().split(" ");
		int a[] = new int[n];

		long sum = 0;
		long min = Long.MAX_VALUE;
		long count = 0;
		for (int i = 0; i < n; i++) {
			a[i] = Integer.parseInt(str[i]);
			sum += Math.abs(a[i]);
			min = Math.min(min, Math.abs(a[i]));
			if (a[i] < 0)
				count++;
		}

		if (count % 2 == 0)
			System.out.println(sum);
		else
			System.out.println(sum - 2 * min);
	}
}
