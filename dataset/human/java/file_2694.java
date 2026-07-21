import java.util.*;
import java.sql.*;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		char[] s = sc.next().toCharArray();
		char[] t = sc.next().toCharArray();
		
		Arrays.sort(s);
		Arrays.sort(t);
		
		for (int i = 0; i < t.length / 2; i++) {
			char tmp = t[i];
			t[i] = t[t.length - i - 1];
			t[t.length - i - 1] = tmp; 
		}
		
		String ss = String.valueOf(s);
		String st = String.valueOf(t);
		
		if (ss.compareTo(st) < 0) {
			System.out.println("Yes");
		} else {
			System.out.println("No");
		}
	}
}
