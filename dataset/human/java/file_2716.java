import java.util.*;

public class Main {
	public static void main(String[] args) throws Exception{
		Scanner scn = new Scanner(System.in);
		String s = scn.next();
		String t = scn.next();
      	char[] ss = s.toCharArray();
      	Arrays.sort(ss);
      	String sss = new String(ss);
      	char[] tt = t.toCharArray();
      	Arrays.sort(tt);
      	String T = new String(tt);
      	String ttt = new StringBuilder(T).reverse().toString();
      	if (sss.compareTo(ttt) < 0)
			System.out.println("Yes");
		else
			System.out.println("No");
	}
}
