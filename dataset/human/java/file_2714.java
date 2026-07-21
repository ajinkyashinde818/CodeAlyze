import java.util.Arrays;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String s = sc.next();
		String t = sc.next();

		char[] sch = s.toCharArray();
		Arrays.sort(sch);
		String s_asc = new String(sch);

		char[] tch = t.toCharArray();
		Arrays.sort(tch);
		String t_asc = new String(tch);
		String t_desc = new StringBuilder(t_asc).reverse().toString();

		if (s_asc.compareTo(t_desc) < 0)
			System.out.println("Yes");
		else
			System.out.println("No");
		sc.close();
	}

}
