import java.util.Arrays;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String s = sc.next(), t = sc.next();
		sc.close();
		char c1[] = s.toCharArray(), c2[] = t.toCharArray();

		Arrays.sort(c1);
		Arrays.sort(c2);

		String ss = new String(c1), tt = new String(c2);
		String ttr = new StringBuilder(tt).reverse().toString();

		if (ss.compareTo(ttr) < 0) {
			System.out.println("Yes");
		} else {
			System.out.println("No");
		}
	}
}
