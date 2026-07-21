import java.util.*;
// warm-up
public class Main {

	static void solve() {
		Scanner sc = new Scanner(System.in);
		String s = "abc", t = sc.next();
		System.out.println(t.indexOf('a')==-1||t.indexOf('b')==-1||t.indexOf('c')==-1 ? "No" : "Yes");
		sc.close();		
	}

	public static void main(String args[]) {
		solve();
	}

}
