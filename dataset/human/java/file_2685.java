import java.util.Arrays;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		char[] s = sc.next().toCharArray();
		char[] t = sc.next().toCharArray();

		Arrays.sort(s);
		Arrays.sort(t);

		StringBuilder sb = new StringBuilder();
		for (int i = 0; i < s.length; i++) {
			sb.append(s[i]);
		}
		String S = sb.toString();
		sb = new StringBuilder();
		
		for (int i = 0; i < t.length; i++) {
			sb.append(t[i]);
		}

		String T = sb.reverse().toString();
		
        if (S.compareToIgnoreCase(T) < 0) {
        	System.out.println("Yes");
        } else {
        	System.out.println("No");
        }

	}
}
