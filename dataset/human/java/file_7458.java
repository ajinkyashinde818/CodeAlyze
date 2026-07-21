import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		try (Scanner sc = new Scanner(System.in)) {
			String str = sc.next();
			int len = str.length();
			while (len > 0) {
				String five = str.substring(len - 5, len);
				if (five.equals("erase") || five.equals("dream")) {
					len -= 5;
					continue;
				} else {
					String six = str.substring(len - 6, len);
					if (six.equals("eraser")) {
						len -= 6;
						continue;
					} else {
						String seven = str.substring(len - 7, len);
						if (seven.equals("dreamer")) {
							len -= 7;
							continue;
						}
					}
				}
				break;
			}
			if (len == 0) {
				System.out.println("YES");
			} else {
				System.out.println("NO");
			}
		}
	}
}
