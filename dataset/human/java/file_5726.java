import java.util.*;

public class Main {
	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);

		String s = sc.next();
		Character[] n = new Character[3];

		for (int i = 0; i < 3; i++) {
			n[i] = s.charAt(i);
		}
		if (Arrays.asList(n).contains('a') && Arrays.asList(n).contains('b') && Arrays.asList(n).contains('c')) {
			System.out.println("Yes");
		} else {
			System.out.println("No");
		}
	}
}
