import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Comparator;

public class Main {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		String str[] = br.readLine().split(" ");

		int n = Integer.parseInt(str[0]);
		int r = Integer.parseInt(str[1]);

		if (n >= 10) {
			System.out.println(r);
		} else {
			System.out.println(r + (100 * (10 - n)));
		}
	}
}
