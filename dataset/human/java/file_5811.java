import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class Main {

	public static void main(String[] args) {
		@SuppressWarnings("resource")
		Scanner sc = new Scanner(System.in);

		String s = sc.next();

		Set<Character> c = new HashSet<>();
		c.add(s.charAt(0));
		c.add(s.charAt(1));
		c.add(s.charAt(2));

		if(c.size() == 3) {
			System.out.println("Yes");
		}else {
			System.out.println("No");
		}

	}

}
