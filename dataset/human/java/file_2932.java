import java.util.Scanner;
public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = Integer.parseInt(sc.next());
		int m = Integer.parseInt(sc.next());
		boolean[] able1 = new boolean[n + 1];
		boolean[] ableN = new boolean[n + 1];
		for (int i = 0; i < m; i++) {
			int a = Integer.parseInt(sc.next());
			int b = Integer.parseInt(sc.next());
			if (a > b) {
				int tem = a;
				a = b;
				b = tem;
			}
			if (a == 1)
				able1[b] = true;
			if (b == n)
				ableN[a] = true;
		}
		for (int i = 1; i <= n; i++) {
			if (able1[i] && ableN[i]) {
				System.out.println("POSSIBLE");
				return;
			}
		}
		System.out.println("IMPOSSIBLE");
	}
}
