import java.util.Scanner;

public class Main {

	static Scanner sc = new Scanner(System.in);

	public static void main(String[] args) throws Exception {
		int N = sc.nextInt();
		for (int i = 0; i < N; ++i) {
			System.out.println(format(parse(sc.next()) + parse(sc.next())));
		}
	}

	static int parse(String s) {
		int ret = 0;
		int d = 1;
		for (char c : s.toCharArray()) {
			if ('2' <= c && c <= '9') {
				d = c - '0';
			} else {
				if (c == 'm') {
					ret += d * 1000;
				} else if (c == 'c') {
					ret += d * 100;
				} else if (c == 'x') {
					ret += d * 10;
				} else if (c == 'i') {
					ret += d;
				}
				d = 1;
			}
		}
		return ret;
	}

	static String format(int v) {
		String ret = digit(v, 1000, 'm');
		v %= 1000;
		ret += digit(v, 100, 'c');
		v %= 100;
		ret += digit(v, 10, 'x');
		v %= 10;
		ret += digit(v, 1, 'i');
		return ret;
	}

	static String digit(int v, int div, char c) {
		int count = v / div;
		if (count == 0) {
			return "";
		} else if (count == 1) {
			return c + "";
		} else {
			return "" + count + c;
		}
	}

}
