import java.util.Scanner;
import java.util.Stack;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		for (int i = 0; i < n; i++) {
			int a = ConvertInt(sc.next());
			int b = ConvertInt(sc.next());
			System.out.println(ConvertMCXI(a + b));
		}
		sc.close();
	}

	private static int ConvertInt(String mcxi) {
		int ans = 0;
		String s = mcxi;

		Stack<Character> stack = new Stack<Character>();
		stack.push('1');
		stack.push('1');
		stack.push('1');
		stack.push('1');

		for (int i = 0; i < s.length(); i++) {
			char ch = s.charAt(i);
			switch (ch) {
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9':
				stack.push(ch);
				break;

			case 'm':
				ans += Integer.parseInt("" + stack.pop()) * 1000;
				break;
			case 'c':
				ans += Integer.parseInt("" + stack.pop()) * 100;
				break;
			case 'x':
				ans += Integer.parseInt("" + stack.pop()) * 10;
				break;
			case 'i':
				ans += Integer.parseInt("" + stack.pop());
				break;
			}
		}
		return ans;
	}

	private static String ConvertMCXI(int num) {
		int n = num;
		int m, c, x, i;

		i = n % 10;
		n = n / 10;
		x = n % 10;
		n = n / 10;
		c = n % 10;
		n = n / 10;
		m = n % 10;
		n = n / 10;

		StringBuilder sb = new StringBuilder();

		if (m != 0 && m != 1)
			sb.append("" + m + 'm');
		else if (m == 1)
			sb.append('m');

		if (c != 0 && c != 1)
			sb.append("" + c + 'c');
		else if (c == 1)
			sb.append('c');

		if (x != 0 && x != 1)
			sb.append("" + x + 'x');
		else if (x == 1)
			sb.append('x');

		if (i != 0 && i != 1)
			sb.append("" + i + 'i');
		else if (i == 1)
			sb.append('i');

		return new String(sb);
	}
}
