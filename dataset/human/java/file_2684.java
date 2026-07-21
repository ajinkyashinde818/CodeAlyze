import java.util.*;
 
public class Main {
 
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String S = sc.next();
		String T = sc.next();
		char[] s = S.toCharArray();
		char[] t = T.toCharArray();
		Arrays.sort(s);
		Arrays.sort(t);
		for (int i = 0; i < Math.min(s.length, t.length); i++) {
			if (s[i] == t[t.length-i-1]) {
				continue;
			} else if (s[i] < t[t.length-i-1]) {
				System.out.println("Yes");
				return;
			} else {
				System.out.println("No");
				return;
			}
		}
		System.out.println(s.length < t.length ? "Yes" : "No");
	}
}
