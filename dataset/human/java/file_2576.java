import java.util.Arrays;
import java.util.Collections;
import java.util.Scanner;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

class Main {
	public static void main(String args[]) {
		Scanner sc = new Scanner(System.in);
		String s = sc.next();
		String t = sc.next();
		
		char[] c1 = s.toCharArray();
		Arrays.sort(c1);
		
		char[] c2 = t.toCharArray();
		Arrays.sort(c2);
		
		int n = Math.min(c1.length, c2.length);
		String ans = "Yes";
		for (int i = 0; i < n; i++) {
			if (c1[i] > c2[c2.length - 1 - i]) {
				ans = "No";
				break;
			}
			
			if (c1[i] == c2[c2.length - 1 - i]) {
				if (i == n - 1 && c1.length >= c2.length) {
					ans = "No";
				}
				continue;
			}
			if (c1[i] < c2[c2.length - 1 - i]) break;
		}
		
		
		
		System.out.println(ans);
		
	}
}
