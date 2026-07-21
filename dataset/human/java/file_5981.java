import java.util.Arrays;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String s = sc.next();
		String[] sl = s.split("");
		Arrays.sort(sl);
		s = String.join("", sl);
		if (s.equals("abc")) {
			System.out.println("Yes");
		} else {
			System.out.println("No");
		}

	}
}
