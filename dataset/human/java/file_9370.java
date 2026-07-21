import java.util.*;
public class Main {

	static void solve() {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt(), t = 0;
		while (n-->0) {
			int a = sc.nextInt(), b = sc.nextInt();
			if (a==b) t++; else t=0;
			if (t==3) break;
		}
		System.out.println(t==3 ? "Yes" : "No");
		sc.close();			
	}

	public static void main(String args[]) {
		solve();
	}

}
