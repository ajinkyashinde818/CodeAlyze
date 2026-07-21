import java.util.Arrays;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String s = sc.next();
		String t = sc.next();
		char[] sa = new char[s.length()];
		char[] ta = new char[t.length()];

		sa = s.toCharArray();
		ta = t.toCharArray();

		Arrays.sort(sa);
		Arrays.sort(ta);

		s = String.valueOf(sa);
		t = new StringBuilder(String.valueOf(ta)).reverse().toString();

		if (t.compareTo(s) > 0) {
			System.out.println("Yes");
		} else {
			System.out.println("No");
		}

		sc.close();

	}

}
