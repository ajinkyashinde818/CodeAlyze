import java.util.Arrays;
import java.util.Scanner;

public class Main {

	public static void main(String... nui) {
		
		Scanner sc = new Scanner(System.in);

		char[] s = sc.next().toCharArray();
		char[] t = sc.next().toCharArray();
		
		Arrays.sort(s);
		Arrays.sort(t);
		
		String l = new String(s);
		String r = new StringBuilder(new String(t)).reverse().toString();
		
		System.out.println((l.compareTo(r) < 0) ? "Yes" : "No");
		
	}

}
