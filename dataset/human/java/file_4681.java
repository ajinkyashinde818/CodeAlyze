import java.util.*;
public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String N = sc.next();
		int d = N.length();
		int[][] dp = new int[d+1][2];
		dp[0][1] = 1;
		for(int i = 1; i <= d; i++) {
			int x = Character.getNumericValue(N.charAt(i-1));
			dp[i][0] = Math.min(dp[i-1][0] + x, dp[i-1][1] + 10 - x);
			dp[i][1] = Math.min(dp[i-1][0] + x + 1, dp[i-1][1] + 9 - x);
		}
		System.out.println(dp[d][0]);
	}

}
