import java.math.BigDecimal;
import java.util.Arrays;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		String s = sc.nextLine();
		String t = sc.nextLine();
		String S = "";
		String T = "";
		char[] chars = new char[s.length()]; 
		char[] chart = new char[t.length()]; 
		for (int i = 0; i < s.length(); i++) chars[i] = s.charAt(i);
		for (int i = 0; i < t.length(); i++) chart[i] = t.charAt(i);

		Arrays.sort(chars);
		Arrays.sort(chart);
		
		for (int i = 0; i < s.length(); i++) S += chars[i];
		for (int i = 0; i < t.length(); i++) T += chart[t.length() - i - 1];
		String ans = "No";
		if (S.compareTo(T) < 0) ans = "Yes"; 
		
		System.out.println(ans);
	}

}
