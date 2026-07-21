import java.util.*;
 
public class Main {
	public static void main (String[] args) {
		Scanner in = new Scanner(System.in);
		
		String s = in.next();
		char[] s_chars = s.toCharArray();
        Arrays.sort(s_chars);
        String s_asc = new String(s_chars);
		
		String t = in.next();
		char[] t_chars = t.toCharArray();
		Arrays.sort(t_chars);
		String t_asc = new String(t_chars);
		String t_desc = new StringBuilder(t_asc).reverse().toString();
		
		if (s_asc.compareTo(t_desc) < 0)
			System.out.println("Yes");
		else
			System.out.println("No");
	}
}
