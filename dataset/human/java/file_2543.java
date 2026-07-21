import java.util.Arrays;
import java.util.Scanner;



public class Main{

	public static void main(String args[]){

		Scanner sc = new Scanner(System.in);
		String s = sc.next();
		String t = sc.next();
		
		char cs[] = s.toCharArray();
		char ct[] = t.toCharArray();
		
		Arrays.sort(cs);
		Arrays.sort(ct);
		
		String ss = new String(cs);
		String tt = new String(ct);
		
		StringBuilder a = new StringBuilder(tt);
		a.reverse();
		String ttt = new String(a);
		
		
		if(ss.compareTo(ttt) < 0) {
			System.out.println("Yes");
		}else {
			System.out.println("No");
		}
		
	}
}
