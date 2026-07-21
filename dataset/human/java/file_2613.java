import java.util.Arrays;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		char[] s = sc.next().toCharArray(), t = sc.next().toCharArray();
		Arrays.sort(s);
		Arrays.sort(t);
		String s1 = new String(s);
		String t1 = new String(new StringBuilder(new String(t)).reverse().toString());
		System.out.println(s1.compareTo(t1) < 0 ? "Yes":"No");
	}
}
