import java.util.Arrays;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner((System.in));
		String s = sc.next();
		String t = sc.next();
		String[] a = {"a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "n", "m", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z"};
		int[] x = new int[s.length()];
		int[] y = new int[t.length()];
		String ans = "No";
		
		for (int i = 0; i < s.length(); i++) {
			for (int j = 0; j < 26; j++) {
				if (a[j].equals(s.substring(i, i + 1))) {
					x[i] = j;
				}
			}
		}

		for (int i = 0; i < t.length(); i++) {
			for (int j = 0; j < 26; j++) {
				if (a[j].equals(t.substring(i, i + 1))) {
					y[i] = j;
				}
			}
		}
		
		Arrays.sort(x);
		Arrays.sort(y);
		
		if (x[0] < y[t.length() - 1]) {
			ans = "Yes";
		} else if (x[0] == y[t.length() - 1]) {
			if (s.length() < t.length()) {
				ans = "Yes";
				for (int i = 1; i < s.length(); i++) {
					if (x[i] != y[t.length() - (1 + i)]) {
						ans = "No";
						break;
					}
				}
			}
		}
		
		System.out.println(ans);
		sc.close();
	}
}
