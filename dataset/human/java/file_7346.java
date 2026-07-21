import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String s = sc.nextLine();
		Set<String> m = new HashSet<>();
		m.add("eraser");
		m.add("dreamer");
		m.add("dream");
		m.add("erase");
		boolean[] a = new boolean[s.length() + 1];
		a[0] = true;
		for (int i = 5; i <= s.length(); i++) {
			if (a[i - 5] && m.contains(s.substring(i - 5, i))) a[i] = true;
			if (i - 6 >= 0 && a[i - 6] && m.contains(s.substring(i - 6, i))) a[i] = true;
			if (i - 7 >= 0 && a[i - 7] && m.contains(s.substring(i - 7, i))) a[i] = true;
		}

		if (a[s.length()]) {
			System.out.println("YES");
		} else {
			System.out.println("NO");
		}
	}
}
