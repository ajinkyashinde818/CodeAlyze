import java.util.Scanner;
import java.util.Set;
import java.util.HashSet;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		Set<Character> set = new HashSet<>();
		String s = sc.next();
		for (char c : s.toCharArray()) {
			set.add(c);
		}
		
		System.out.println(set.size() == 3 ? "Yes" : "No");
	}
}
