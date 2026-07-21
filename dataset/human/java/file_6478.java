import java.util.*;
// warm-up
// Even better without extra space with a simple branch. Thanks to Editorial. 
// Technically no need for another loop and a map to cross check.
public class Main {

	static void solve() {
		Scanner sc = new Scanner(System.in);
		int K = sc.nextInt(), s = sc.nextInt(), t=0;
		for (int i=0; i<=K; i++) {
			for (int j=0; j<=K; j++) {
				int z = s-i-j;
				if (z>=0 && z<=K) t++;
			}
		}
		System.out.println(t);
		sc.close();			
	}

	public static void main(String args[]) {
		solve();
	}

}
