import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

import static java.lang.Integer.parseInt;

/**
 * Japanese Calendar
 */
public class Main {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String line;
		String[] words;

		line = br.readLine();

		int E, Y;
		E = parseInt(line.substring(0, line.indexOf(' ')));
		Y = parseInt(line.substring(line.indexOf(' ') + 1));

		switch (E) {
			case 0:
				if (Y < 1912) {
					System.out.printf("M%d%n", Y - 1868 + 1);
				} else if (Y < 1926) {
					System.out.printf("T%d%n", Y - 1912 + 1);
				} else if (Y < 1989) {
					System.out.printf("S%d%n", Y - 1926 + 1);
				} else {
					System.out.printf("H%d%n", Y - 1989 + 1);
				}
				break;
			case 1:
				System.out.println(1868 + Y - 1);
				break;
			case 2:
				System.out.println(1912 + Y - 1);
				break;
			case 3:
				System.out.println(1926 + Y - 1);
				break;
			case 4:
				System.out.println(1989 + Y - 1);
				break;
		}
	}
}
