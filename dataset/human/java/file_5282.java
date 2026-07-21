import java.util.*;
public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		for(;;) {
			int n = sc.nextInt();
			if( n == 0 ) break;
			int[][] dp = new int[n+1][n+1];
			int max = 0;
			for(int i=1;i<=n;i++) {
				String line = sc.next();
				for(int j=1;j<=n;j++) if( line.charAt(j-1) == '.' ) {
					dp[i][j] = Math.min( Math.min(dp[i-1][j], dp[i][j-1]), dp[i-1][j-1] )+1;
					max = Math.max(max, dp[i][j]);
				}
			}
			System.out.println(max);
		}
	}
}
