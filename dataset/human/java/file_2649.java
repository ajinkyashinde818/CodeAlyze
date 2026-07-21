import java.util.Arrays;
import java.util.Comparator;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);
		String s = sc.next();
		String t = sc.next();
		char[] c1 = s.toCharArray();
		char[] c2 = t.toCharArray();
		Character[] c3 = new Character[t.length()];
		for(int i = 0 ; i < t.length() ; i++) {
			c3[i] = c2[i];
		}
		Arrays.sort(c1);
		Arrays.sort(c3, Comparator.reverseOrder());
		for(int i = 0 ; i < t.length() ; i++) {
			c2[i] = c3[i];
		}

		if(String.valueOf(c1).compareTo(String.valueOf(c2)) < 0) {
			System.out.println("Yes");
		} else {
			System.out.println("No");
		}

//		System.out.println();

		sc.close();

	}

}
