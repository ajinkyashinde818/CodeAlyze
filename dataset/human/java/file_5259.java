import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		try(Scanner sc = new Scanner(System.in)){
			while(sc.hasNext()) {
				int n=sc.nextInt();
				if(n==0) break;
				char[][] board=new char[n][n];
				for(int i=0; i<n; i++) {
					String str=sc.next();
					for(int j=0; j<n; j++) {
						board[i][j]=str.charAt(j);
					}
				}
				int[][] dp=new int[n][n];
				for(int k=0; k<n; k++) {
					dp[0][k]=(board[0][k]=='.'?1:0);
					dp[k][0]=(board[k][0]=='.'?1:0);
				}
				for(int i=1; i<n; i++) {
					for(int j=1; j<n; j++) {
						if(board[i][j]=='.')dp[i][j]=Math.min(dp[i-1][j-1],Math.min(dp[i-1][j], dp[i][j-1]))+1;
						else dp[i][j]=0;
					}
				}
				int ans=0;
				for(int i=0; i<n; i++) {
					for(int j=0; j<n; j++) {
						ans=Math.max(ans, dp[i][j]);
					}
				}
				System.out.println(ans);
			}

		}

	}
}
