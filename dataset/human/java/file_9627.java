import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.Map;

public class Main {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		int n = Integer.parseInt(br.readLine());

		int count = 0;
		for (int i = 0; i < n; i++) {
			String str[] = br.readLine().split(" ");

			int a = Integer.parseInt(str[0]);
			int b = Integer.parseInt(str[1]);

			if (a == b) {
				count++;
			} else {
				count = 0;
			}
			if (count >= 3) {
				System.out.println("Yes");
				return;
			}
		}
		System.out.println("No");
	}
}
