import java.util.Arrays;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String s = sc.next();
		String t = sc.next();

		char[] sChar = s.toCharArray();
		char[] tChar = t.toCharArray();

		Arrays.sort(sChar);
		Arrays.sort(tChar);

		String sString = String.valueOf(sChar);
		StringBuffer sb = new StringBuffer(String.valueOf(tChar));
		String tString = sb.reverse().toString();

		System.out.println(sString.compareTo(tString) < 0 ? "Yes" : "No");
	}
}
