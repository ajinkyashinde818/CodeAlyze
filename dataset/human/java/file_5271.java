import java.util.Scanner;

public class Main{

	public static void main(String[] args) {
		new Main().main();
	}

	void main() {
		Scanner sc = new Scanner(System.in);
		while(true) {
			int n = sc.nextInt();
			if(n==0) break;
			char[][] c = new char[n][n];
			for(int i=0;i<n;i++) {
				String s = sc.next();
				c[i] = s.toCharArray();
			}
//			for(int i=0;i<n;i++) {
//				for(int j=0;j<n;j++) {
//					System.out.print(c[i][j] + " ");
//				}
//				System.out.println();
//			}
			int[][] dp = new int[n][n];
			for(int j=0;j<n;j++) {
				dp[0][j] = (c[0][j] == '.'?1:0);
			}
			for(int i=0;i<n;i++) {
				dp[i][0] = (c[i][0] == '.'?1:0);
			}
			for(int i=1;i<n;i++) {
				for(int j=1;j<n;j++) {
					if(c[i][j] == '.') {
						dp[i][j] = Math.min(dp[i-1][j-1], Math.min(dp[i-1][j], dp[i][j-1]))+1;
					}else {
						dp[i][j] = 0;
					}
				}
			}
			int ans = 0;
			for(int i=0;i<n;i++) {
				for(int j=0;j<n;j++) {
					ans = Math.max(ans , dp[i][j]);
				}
			}
			System.out.println(ans);
		}
	}
}
