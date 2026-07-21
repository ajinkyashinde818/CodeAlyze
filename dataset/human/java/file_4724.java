import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		char []s = sc.next().toCharArray();
		
		int n = s.length;
		
		int []t = new int [n];
		for(int i = 0 ; i < n ;i++) {
			t[i] = s[i] - '0';
		}
		
		int[][]dp = new int [n+1][2]; 
		for(int i = 0 ; i <= n ;i++) {
			dp[i][0] = 1000000000;
			dp[i][1] = 1000000000;
		}
		dp[1][0] = t[0];
		dp[1][1] = 11 - t[0];
		
		for(int i = 1 ; i < n ;i++) {
			dp[i+1][0] = Math.min(dp[i][0] + t[i], dp[i][1] + t[i]);
			dp[i+1][1] = Math.min(dp[i][0] + 11 - t[i], dp[i][1] + 9 - t[i]);
		}

		System.out.println(Math.min(dp[n][0],dp[n][1]));
		
		

	}

}
