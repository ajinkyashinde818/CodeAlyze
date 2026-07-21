import java.util.Arrays;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		String s = sc.next();
		String t = sc.next();
		
		char[] cs = s.toCharArray();
		char[] ct = t.toCharArray();
		
		Arrays.sort(cs);
		Arrays.sort(ct);
		
		s = new String(cs);
		t = new String(ct);
		t = new StringBuilder(t).reverse().toString();
		
		System.out.println(s.compareTo(t) < 0 ? "Yes" : "No");
		
		sc.close();
	}
}
