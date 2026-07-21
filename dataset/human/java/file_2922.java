import java.util.ArrayList;
import java.util.Scanner;

public class Main {
	private Scanner sc;
	
	public static void main(String[] args) {
		new Main();
	}
	
	public Main() {
		sc = new Scanner(System.in);

		String[] nico = sc.nextLine().split(" ");
		int n = Integer.parseInt(nico[0]);
		int m = Integer.parseInt(nico[1]);

		String ans = "IMPOSSIBLE";

		boolean[] flag = new boolean[n];
		for (int i = 0; i < n; i++) {
			flag[i] = false;
		}
		
		for (int i = 0; i < m; i++) {
			String[] tmp = sc.nextLine().split(" ");
			int t0 = Integer.parseInt(tmp[0]);
			int t1 = Integer.parseInt(tmp[1]);
			
			if ((t0 != 1) && (t0 != n) && (t1 != 1) && (t1 != n)) continue;

			if ((t0 == 1) || (t0 == n)) {
				if (flag[t1] == true) {
					ans = "POSSIBLE";
					break;
				}
				flag[t1] = true;
			}
			
			if ((t1 == 1) || (t1 == n)) {
				if (flag[t0] == true) {
					ans = "POSSIBLE";
					break;
				}
				flag[t0] = true;
			}
		}
		System.out.println(ans);
	}
}
