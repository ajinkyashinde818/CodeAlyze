import java.util.Arrays;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		// You - N = T => T + N = You
		Scanner sc = new Scanner(System.in);
		String NS = sc.next();
		int len = NS.length();
		int N[] = new int[len];
		for(int i = 0 ; i < len ; ++i){
			N[i] = NS.charAt(len - 1 - i) - '0';
		}
		// 9 6
		//   
		//   6
		int dp[][] = new int[len][2];
		dp[0][0] = N[0];
		dp[0][1] = 10 - N[0];
		for(int i = 1 ; i < len ; ++i){
			int n = N[i];
			dp[i][0] = dp[i - 1][0] + n;
			if(n != 9){
				dp[i][0] = Math.min(dp[i][0], dp[i - 1][1] + (n + 1));				
			}
			dp[i][1] = dp[i - 1][0] + (10 - n);
			if(n == 9){
				dp[i][1] = Math.min(dp[i][1], dp[i - 1][1]);								
			}else{
				dp[i][1] = Math.min(dp[i][1], dp[i - 1][1] + (10 - (n + 1)));				
			}
		}	
		int ret = Math.min(dp[len - 1][0], dp[len - 1][1] + 1);
//		System.out.println(Arrays.deepToString(dp));
		System.out.println(ret);
	}
}
