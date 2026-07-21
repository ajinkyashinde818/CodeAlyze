import java.util.*;
public class Main {

	public static void main(String[] args) {
		Scanner stdIn = new Scanner(System.in);
		String s = stdIn.next();
		char[] S = s.toCharArray();
		Arrays.sort(S);
		String s1 = new String(S);
		String t = stdIn.next();
		char[] T = t.toCharArray();
		Arrays.sort(T);
		String t1 = new String(T);
		String t2 = new StringBuilder(t1).reverse().toString();
		if(s1.compareTo(t2) < 0) {
			System.out.println("Yes");
		}
		else {
			System.out.println("No");
		}
	}

}
