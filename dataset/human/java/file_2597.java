import java.util.*;
public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String s = sc.next();
		String t = sc.next();
		char[] s2 = s.toCharArray();
		char[] t2 = t.toCharArray();
		Arrays.sort(s2);
		Arrays.sort(t2);
		t2[0]=t2[t2.length-1];
		String S = String.valueOf(s2);
		String T = String.valueOf(t2);
		if(S.compareTo(T)<0) {
			System.out.println("Yes");
		}else {
			System.out.println("No");
		}
	}
 
}
