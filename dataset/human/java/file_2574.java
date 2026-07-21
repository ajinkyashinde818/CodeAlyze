import java.util.Arrays;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		StringBuilder sb = new StringBuilder();
		char[] s = sc.next().toCharArray();
		char[] t = sc.next().toCharArray();
		Arrays.sort(s);
		Arrays.sort(t);
		for (int i = 0; i < Math.min(s.length, t.length); i++) {
			if (s[i] == t[t.length - 1 - i]) {

			} else if (s[i] > t[t.length - 1 - i]) {
				System.out.println("No");
				return;
			} else if (s[i] < t[t.length - 1 - i]) {
				System.out.println("Yes");
				return;
			}
		}
		if (s.length < t.length) {
			System.out.println("Yes");
		}else {
			System.out.println("No");
		}
	}
}
