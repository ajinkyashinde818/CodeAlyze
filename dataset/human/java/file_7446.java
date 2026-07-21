import java.util.*;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String s = sc.next();
		
		if (judge(s, 0)) {
			System.out.println("YES");
		} else {
			System.out.println("NO");
		}
	}
	
	public static boolean judge(String s, int i) {
		if (i == s.length()) {
			return true;
		}
		
		boolean f = false;
		
		if (s.length() >= i + 7 && s.substring(i, i + 7).equals("dreamer")) {
			f |= judge(s, i + 7);
		} 
		if (s.length() >= i + 5 && s.substring(i, i + 5).equals("dream")) {
			f |= judge(s, i + 5);
		} 
		if (s.length() >= i + 6 && s.substring(i, i + 6).equals("eraser")) {
			f |= judge(s, i + 6);
		} 
		if (s.length() >= i + 5 && s.substring(i, i + 5).equals("erase")) {
			f |= judge(s, i + 5);
		} 
		
		return f;
	}
}
