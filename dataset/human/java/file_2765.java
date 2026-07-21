import java.util.*;
public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String s = sc.next();
		String t = sc.next();
		char[] s1 = s.toCharArray();
		char[] t1 = t.toCharArray();
		Arrays.sort(s1);
		Arrays.sort(t1);
		t1[0]=t1[t1.length-1];
		String S = String.valueOf(s1);
		String T = String.valueOf(t1);
		if(S.compareTo(T)<0) {
			System.out.println("Yes");
		}else {
			System.out.println("No");
		}
	}

}
