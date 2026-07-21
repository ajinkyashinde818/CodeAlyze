import java.util.Arrays;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		final Scanner sc = new Scanner(System.in);
		String s = sc.next();
		char[] a = s.toCharArray();
		Arrays.sort(a);
		System.out.println(new String(a).equals("abc") ? "Yes" : "No");
	}
}
