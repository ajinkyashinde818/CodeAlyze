import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner in = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
		String s = in.next();
		int q = in.nextInt();
		boolean rev = false;
		char[] pr = new char[q];
		int ppr = 0;
		char[] po = new char[q];
		int ppo = 0;
		for (int i = 0; i < q; i++) {
			int t = in.nextInt();
			if (t == 1)
				rev ^= true;
			else {
				int f = in.nextInt();
				String c = in.next();
				if ((f == 1 && rev) || (f != 1 && !rev))
					po[ppo++] = c.charAt(0);
				else
					pr[ppr++] = c.charAt(0);
			}
		}
		if (rev) {
			System.out.print(reverse(po, ppo));
			System.out.print(reverse(s.toCharArray(), s.length()));
			System.out.println(String.valueOf(pr, 0, ppr));
		} else {
			System.out.print(reverse(pr, ppr));
			System.out.print(s);
			System.out.println(String.valueOf(po, 0, ppo));
		}
	}

	private static String reverse(char[] c, int cp) {
		char[] cr = new char[cp];
		for (int i = 0; i < cp; i++)
			cr[i] = c[cp - i - 1];

		return String.valueOf(cr);
	}
}
