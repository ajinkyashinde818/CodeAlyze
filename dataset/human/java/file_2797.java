import java.util.*;

public class Main {
	public static void main(String[] args) {
		int i,j;
		Scanner sc = new Scanner(System.in);
		String s = sc.next();
		String t = sc.next();
		sc.close();
		char[] sa = s.toCharArray();
		Arrays.sort(sa);
		s = new String(sa);
		char[] ta = t.toCharArray();
		Arrays.sort(ta);
		char tmp;
		for(i=0;i<ta.length/2;i++) {
			tmp = ta[i];
			ta[i] = ta[ta.length-1-i];
			ta[ta.length-1-i] = tmp;
		}
		t = new String(ta);
//		System.out.println(s+":"+t);
		System.out.println(s.compareTo(t) < 0?"Yes":"No");
	}
}
