import java.util.*;
import java.lang.*;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String ss = sc.next();
		StringBuilder s = new StringBuilder(ss);
		boolean bre = false;
		while (s.length() > 0) {
			if (s.substring(s.length() - 5).equals("dream") || s.substring(s.length() - 5).equals("erase")) {
				s.delete(s.length() - 5, s.length());
			} else if (s.substring(s.length() - 6).equals("eraser")) {
				s.delete(s.length() - 6, s.length());;
			} else if (s.substring(s.length() - 7).equals("dreamer")) {
				s.delete(s.length() - 7, s.length());
			} else {
				bre = true;
				break;
			}
		}
		if (bre) {
			System.out.println("NO");
		} else {
			System.out.println("YES");
		}
	}
}
