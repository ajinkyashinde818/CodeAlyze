import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		long n = Long.parseLong(br.readLine());

		if (n % 2 != 0) {
			System.out.println("0");
		} else {
			long count = 0;
			n /= 2;
			while (n > 0) {
				count += n / 5;
				n /= 5;
			}

			System.out.println(count);
		}
	}
}
