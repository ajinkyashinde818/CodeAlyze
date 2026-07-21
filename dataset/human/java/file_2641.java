import java.util.*;
// warm-up
public class Main {

	static void solve() {
		Scanner sc = new Scanner(System.in);
		int[] c = new int[256];
		boolean ok = true;
		String a = sc.next(), b = sc.next();
		for (char ch : b.toCharArray()) c[ch]++;
		for (char ch : a.toCharArray()) {
			if (c[ch]>0) c[ch]--;
			else ok=false;
		}
		if (ok) ok = a.length()<b.length();
		if (!ok) {
			StringBuilder f = new StringBuilder();
			StringBuilder g = new StringBuilder();
			char[] d = a.toCharArray(), e = b.toCharArray();
			Arrays.sort(d); Arrays.sort(e);
			for (char ch : d) f.append(ch);
			for (char ch : e) g.append(ch);
			ok=f.compareTo(g.reverse())<0;
		}
		System.out.println(ok ? "Yes" : "No");
		sc.close();		
	}

	public static void main(String args[]) {
		solve();
	}

}
