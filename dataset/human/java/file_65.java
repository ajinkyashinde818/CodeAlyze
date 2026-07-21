import java.math.BigDecimal;
import java.util.Arrays;
import java.util.Scanner;

public class Main {
	MyScanner sc = new MyScanner();
	Scanner sc2 = new Scanner(System.in);
	int mod = 1000000007;

	void run() {
		int N = sc.nextInt();
		while (N-- > 0) {
			String hex = sc.next();
			String binary = "";
			for (int i = 0; i < 8; i++) {
				int h = 0;
				String tb = "";
				if (Character.isDigit(hex.charAt(i))) {
					h = Integer.valueOf(hex.charAt(i) - '0');
					tb = Integer.toBinaryString(h);
				} else {
					String hoge = "" + hex.charAt(i);
					h = Integer.parseInt(hoge, 16);
					tb = Integer.toBinaryString(h);
				}
				while (tb.length() < 4) {
					tb = "0" + tb;
				}
				binary += tb;
			}
			long integer = 0;
			int index = 0;
			for (int i = 24; i >= 1; i--) {
				int col = (binary.charAt(i) - '0');
				integer += col * Math.pow(2, index);
				index++;
			}
			double small = 0;
			index = 1;
			for (int i = 25; i < 32; i++) {
				int col = (binary.charAt(i) - '0');
				small += col * Math.pow(0.5, index);
				index++;
			}
			BigDecimal bd1 = new BigDecimal(integer + "");
			BigDecimal bd2 = new BigDecimal(small + "");
			System.out.println((binary.charAt(0) == '1' ? "-" : "")
					+ (bd1.add(bd2)));
		}
	}

	public static void main(String[] args) {
		new Main().run();
	}

	void debug(Object... o) {
		System.out.println(Arrays.deepToString(o));
	}

	void debug2(int[][] array) {
		for (int i = 0; i < array.length; i++) {
			for (int j = 0; j < array[i].length; j++) {
				System.out.print(array[i][j]);
			}
			System.out.println();
		}
	}

	class MyScanner {
		int nextInt() {
			try {
				int c = System.in.read();
				while (c != '-' && (c < '0' || '9' < c))
					c = System.in.read();
				if (c == '-')
					return -nextInt();
				int res = 0;
				do {
					res *= 10;
					res += c - '0';
					c = System.in.read();
				} while ('0' <= c && c <= '9');
				return res;
			} catch (Exception e) {
				return -1;
			}
		}

		double nextDouble() {
			return Double.parseDouble(next());
		}

		String next() {
			try {
				StringBuilder res = new StringBuilder("");
				int c = System.in.read();
				while (Character.isWhitespace(c))
					c = System.in.read();
				do {
					res.append((char) c);
				} while (!Character.isWhitespace(c = System.in.read()));
				return res.toString();
			} catch (Exception e) {
				return null;
			}
		}
	}
}
