import java.util.*;

public class Main{
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String s = sc.next();
		String t = sc.next();
		String[] sa = s.split("");
		String[] ta = t.split("");
		Arrays.sort(sa);
		Arrays.sort(ta,Comparator.reverseOrder());
		
		
		s = "";
		t = "";
		for(int i=0; i < sa.length; i++) {
			s = s + sa[i];
		}
		for(int i = 0; i< ta.length; i++) {
			t = t + ta[i];
		}
		String ans;
		if(s.compareTo(t) < 0) {
			ans = "Yes";
		}else {
			ans = "No";
		}
		
		System.out.print(ans);
	}
}
