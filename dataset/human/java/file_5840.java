import java.util.*;
public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String S = sc.nextLine();
		
		S = S.replaceFirst("a", "").replaceFirst("b", "").replaceFirst("c", "");

		if (S.isEmpty()) {
			System.out.println("Yes");
		} else {
			System.out.println("No");
		}
	}
}
