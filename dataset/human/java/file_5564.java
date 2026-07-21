import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		String str[] = br.readLine().split(" ");

		int n = Integer.parseInt(str[0]);
		int k = Integer.parseInt(str[1]);
		long s = Long.parseLong(str[2]);

		for (int i = 0; i < k; i++) {
			if (i == 0)
				System.out.print(s);
			else
				System.out.print(" " + s);
		}

		for (int i = 0; i < n - k; i++) {
			if (s == 1000000000)
				System.out.print(" " + (1));
			else
				System.out.print(" " + (s + 1));
		}
		System.out.println();

	}
}
