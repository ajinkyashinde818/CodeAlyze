import java.util.*;

public class Main {
	public static void main(String[] args) throws Exception{
		Scanner sc = new Scanner(System.in);
		String s = sc.next();
		String t = sc.next();
      	char[] slist = s.toCharArray();
      	Arrays.sort(slist);
      	String sss = new String(slist);
      	char[] tlist = t.toCharArray();
      	Arrays.sort(tlist);
      	String T = new String(tlist);
      	String ttt = new StringBuilder(T).reverse().toString();
      	if (sss.compareTo(ttt) < 0)
			System.out.println("Yes");
		else
			System.out.println("No");
	}
}
