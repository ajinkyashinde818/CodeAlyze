import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String s = sc.next();
		sc.close();
		int n = s.length();
		String ans[] = { "YES", "NO" };
		int a = 0;
		String tmp = "";
		String t[] = { "dream", "dreamer", "erase", "eraser" };
		for (int i = n - 1; i >= 0; --i) {
			if (s.charAt(i) == 'r') {
				if (i < 5) {
					a = 1;
					break;
				} else {
					tmp = s.substring(i - 5, i + 1);
					if (!tmp.equals(t[3])) {
						if (i >= 6) {
							tmp = s.substring(i - 6, i + 1);
							if (!tmp.equals(t[1])) {
								a = 1;
								break;
							} else {
								i = i - 6;
								continue;
							}
						}
						a = 1;
						break;
					} else {
						i = i - 5;
						continue;
					}
				}
			}
			if (s.charAt(i) == 'e') {
				if (i < 4) {
					a = 1;
					break;
				}
				tmp = s.substring(i - 4, i + 1);
				if (tmp.equals(t[2])) {
					i = i - 4;
					continue;
				}
				else {
					a = 1;
					break;
				}
			}
			if (s.charAt(i) == 'm') {
				if (i < 4) {
					a = 1;
					break;
				}
				tmp = s.substring(i - 4, i + 1);
				if (tmp.equals(t[0])) {
					i = i - 4;
					continue;
				}
				else {
					a = 1;
					break;
				}
			}
		}
		System.out.println(ans[a]);

	}

}
