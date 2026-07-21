import java.util.Arrays;
import java.util.Comparator;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		String s = scan.next();
		String t = scan.next();
		int a = s.length();
		int b = t.length();
		char[] cs = new char[s.length()];
		for (int i = 0; i < s.length(); i++) {
			cs[i] = s.charAt(i);
		}
		Character[] ct = new Character[t.length()];
		for (int i = 0; i < t.length(); i++) {
			ct[i] = t.charAt(i);
		}
		Arrays.sort(cs);
		Arrays.sort(ct, Comparator.reverseOrder());
		boolean f = true;
		boolean same = true;
		for (int i = 0; i < Math.min(a, b); i++) {
			if (cs[i] > ct[i]) {
				f = false;
				same = false;
				break;
			}
			if (cs[i] < ct[i]) {
				same = false;
				break;
			}
		}
		if (same == true && a>=b) {
			f = false;
		}
		if (f) {
			System.out.println("Yes");
		} else {
			System.out.println("No");
		}
	}
}
