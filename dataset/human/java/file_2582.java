import java.util.Arrays;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String s = sc.next();
		String t = sc.next();

		if(s.compareTo(t) < 0) {
			System.out.println("Yes");
			return;
		}

		char[] sa = s.toCharArray();
		Arrays.sort(sa);
		s = new String(sa);
		char[] ta = t.toCharArray();
		Arrays.sort(ta);
		t = (new StringBuilder((new String(ta)))).reverse().toString();

		if(s.compareTo(t) < 0) {
			System.out.println("Yes");
			return;
		}

		System.out.println("No");

		return;
	}

}
