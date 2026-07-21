import java.util.Arrays;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {

		Scanner scan = new Scanner(System.in);

		String s = scan.next();
		String t = scan.next();
		String sDash = "";
		String tDash = "";

		char[] sChar = s.toCharArray();
		Arrays.sort(sChar);
		char[] tChar = t.toCharArray();
		Arrays.sort(tChar);

		s = new String(sChar);
		t = new String(tChar);

		StringBuffer sb = new StringBuffer(t);
		t = sb.reverse().toString();

		boolean flag = true;
		for (int i = 0; i < Math.min(s.length(), t.length()); i++) {
			if (s.charAt(i) != t.charAt(i)) flag = false;
			if (s.charAt(i) < t.charAt(i)) {
				System.out.println("Yes");
				System.exit(0);
			}
		}

		if (flag && s.length() < t.length()) System.out.println("Yes");
		else System.out.println("No");
 	}
}
