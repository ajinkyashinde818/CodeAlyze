import java.util.Arrays;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String  s  = sc.next();
		String  t  = sc.next();
		char[]  new_s = s.toCharArray();
		char[]  new_t = t.toCharArray();
		Arrays.sort(new_s);
		Arrays.sort(new_t);
		String _s = new String(new_s);
		String _t = new StringBuffer( new String(new_t) ).reverse().toString();
		if(_s.compareTo(_t)<0) System.out.println("Yes");
		else	                   System.out.println("No");
	}

}
