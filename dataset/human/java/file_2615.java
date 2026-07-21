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

		StringBuilder sbt = new StringBuilder();
		StringBuilder sbs = new StringBuilder();

		for (int i = 0; i < t.length(); i++) {
			sbt = sbt.append(ct[t.length() - 1 - i]);
		}
		for (int i = 0; i < s.length(); i++) {
			sbs = sbs.append(cs[i]);
		}

		String[] str = new String[2];
		str[0] = sbs.toString();
		str[1] = sbt.toString();

		Arrays.sort(str);

		String ans = "";
		if (sbs.toString().equals(sbt.toString())) {
			ans = "No";
		} else if (str[0].equals(sbs.toString())) {
			ans = "Yes";
		} else {
			ans = "No";
		}

		System.out.println(ans);
	}

}
