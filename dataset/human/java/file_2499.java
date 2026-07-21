import java.io.IOException;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		char[] mcxi = { 'm', 'c', 'x', 'i' };
		int n = scanner.nextInt();
		for (int i = 0; i < n; i++) {
			String[] input = new String[2];
			int[] convert = new int[2];
			for (int l = 0; l < input.length; l++) {
				input[l] = scanner.next();
				int a = 1;
				int[] num = new int[4];
				for (int j = 0; j < input[l].length(); j++) {
					char letter = input[l].charAt(j);
					for (int k = 0; k < mcxi.length; k++) {
						if (letter == mcxi[k]) {
							num[k] = a;
							a = 1;
							break;
						}
						if (k == mcxi.length - 1) {
							a = Character.getNumericValue(letter);
						}
					}
				}
				for (int j = 0; j < num.length; j++) {
					convert[l] += num[j] * Math.pow(10, 3 - j);
				}
			}

			String result = String.valueOf(convert[0] + convert[1]);
			while (result.length() < 4) {
				result = "0" + result;
			}
			for (int j = 0; j < result.length(); j++) {
				int number = Character.getNumericValue(result.charAt(j));
				if (number > 1) {
					System.out.print(number);
				}
				if (number > 0) {
					System.out.print(mcxi[j]);
				}
			}

			System.out.print("\n");

		}

	}

	static int nextInt() {
		int c;
		try {
			c = System.in.read();
			while (c != '-' && (c < '0' || c > '9'))
				c = System.in.read();
			if (c == '-')
				return -nextInt();
			int res = 0;
			while (c >= '0' && c <= '9') {
				res = res * 10 + c - '0';
				c = System.in.read();
			}
			return res;
		} catch (IOException e) {
			e.printStackTrace();
		}
		return -1;
	}

}
