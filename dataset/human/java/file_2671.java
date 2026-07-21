import java.util.Arrays;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String s = sc.next();
		String t = sc.next();
		sc.close();
		char[]c1 = s.toCharArray();
		char[]c2 = t.toCharArray();
		Arrays.sort(c1);
		Arrays.sort(c2);
		StringBuilder sb = new StringBuilder(new String(c2));
		sb.reverse();
		String a = new String(c1);

		if(a.compareTo(sb.toString()) < 0) {
			System.out.println("Yes");
		}else {
			System.out.println("No");
		}
	}
}
