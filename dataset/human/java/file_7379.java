import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		String s = scan.next();
		ArrayList<Character> c = new ArrayList<Character>();
		for (int i = 0; i < s.length(); i++) {
			c.add(s.charAt(i));
		}
		Collections.reverse(c);
		boolean f = true;
		int i = 0;
		while(f) {
			if ((c.get(i) == 'm') && (c.get(i+1) == 'a') && (c.get(i+2) == 'e') && (c.get(i+3) == 'r') && (c.get(i+4) == 'd')) {
				i += 5;
				if (i >= s.length()) break;
				continue;
			}
			if ((c.get(i) == 'e') && (c.get(i+1) == 's') && (c.get(i+2) == 'a') && (c.get(i+3) == 'r') && (c.get(i+4) == 'e')) {
				i += 5;
				if (i >= s.length()) break;
				continue;
			}
			if ((c.get(i) == 'r') && (c.get(i+1) == 'e') && (c.get(i+2) == 'm') && (c.get(i+3) == 'a') && (c.get(i+4) == 'e') && (c.get(i+5) == 'r') && (c.get(i+6) == 'd')) {
				i += 7;
				if (i >= s.length()) break;
				continue;
			}
			if ((c.get(i) == 'r') && (c.get(i+1) == 'e') && (c.get(i+2) == 's') && (c.get(i+3) == 'a') && (c.get(i+4) == 'r') && (c.get(i+5) == 'e')) {
				i += 6;
				if (i >= s.length()) break;
				continue;
			}
			f = false;
		}
		if (f) {
			System.out.println("YES");
		} else {
			System.out.println("NO");
		}
	}
}
