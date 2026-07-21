import java.util.*;
// warm-up
public class Main {

	static void solve() {
		Scanner sc = new Scanner(System.in);
		Set<Integer> a = new HashSet<Integer>();
		Set<Integer> b = new HashSet<Integer>();
		int n = sc.nextInt(), no = sc.nextInt();
		while (no-->0) {
			int c = sc.nextInt(), d = sc.nextInt();
			if (c==1||d==1) a.add((c==1) ? d : c); 
			if (c==n||d==n) b.add((c==n) ? d : c); 
		}
		a.retainAll(b);
		System.out.println(a.isEmpty() ? "IMPOSSIBLE" : "POSSIBLE");
		sc.close();		
	}

	public static void main(String args[]) {
		solve();
	}

}
