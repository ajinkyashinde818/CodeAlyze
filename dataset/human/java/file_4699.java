import java.util.Scanner;

public class Main {
	public static void main(String[] args) throws Exception {
		Scanner sc = new Scanner(System.in);
		StringBuilder sb = new StringBuilder(sc.next());
		sc.close();

		sb.reverse();
		int n = sb.length();
		int[] dp0 = new int[n + 1];
		int[] dp1 = new int[n + 1];
		dp1[0] = 2;
		for (int i = 0; i < n; i++) {
			int d = sb.charAt(i) - '0';
			dp0[i + 1] = Math.min(dp0[i] + d, dp1[i] + d);
			dp1[i + 1] = Math.min(dp0[i] + 11 - d, dp1[i] + 9 - d);
		}
		System.out.println(Math.min(dp0[n], dp1[n]));
	}
}
