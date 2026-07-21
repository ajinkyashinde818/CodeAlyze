import java.util.*;
// warm-up
public class Main {

	static void solve() {
		Scanner sc = new Scanner(System.in);
		String s = "0123456789ABCDEF";
		String a = sc.next(), b = sc.next();
		System.out.println(s.indexOf(a)==s.indexOf(b) ? '=' : s.indexOf(a)<s.indexOf(b) ? '<' : '>');
		sc.close();		
	}

	public static void main(String args[]) {
		solve();
	}

}
