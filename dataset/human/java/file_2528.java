import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);

		String str1 = s.next();
		String str2 = s.next();

		int min1 = Integer.MAX_VALUE;
		int max2 = Integer.MIN_VALUE;

		for (int i = 0; i < str1.length(); i++) {
			int strInt1 = (int) str1.charAt(i);
			min1 = Math.min(min1, strInt1);
		}

		for (int i = 0; i < str2.length(); i++) {
			int strInt2 = (int) str2.charAt(i);
			max2 = Math.max(max2, strInt2);
		}

		if ((min1 == max2)) {
			if (str1.replace((char) min1 + "", "").length() == 0 &&
			 	str2.replace((char) max2 + "", "").length() == 0 && 
			 	replace(str1, (char) min1) < replace(str2, (char) max2)) {

				System.out.println("Yes");
				return;
			} else {
				System.out.println("No");
				return;
			}
		}

		String ans = (min1 < max2) ? "Yes" : "No";
		System.out.println(ans);
	}

	static int replace(String str, char target) {
		return str.length() - str.replace(target + "", "").length();
	}
}
