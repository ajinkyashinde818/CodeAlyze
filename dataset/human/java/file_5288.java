/**
 * @author yuichirw
 */
import java.util.*;
import static java.lang.Math.*;

public class Main {
	static int 		n;
	static char[][] field;
	static Scanner 	sc = new Scanner(System.in);

	
	static boolean read() {
		n = sc.nextInt(); sc.nextLine();
		if(n == 0) return false;
		field = new char[n][n];
		for(int i = 0; i < n; i++) {
			field[i] = sc.nextLine().toCharArray();
		}
		return true;
	}
	
	static int solve() {
		int[][] dp = new int[n][n];
		//init
		for(int i = 0; i < n; i++) {
			dp[i][0] = (field[i][0] == '*') ? 0:1;
			dp[0][i] = (field[0][i] == '*') ? 0:1;
		}

		int ans = 0;
		//dp
		for(int i = 1; i < n; i++) {
			for(int j = 1; j < n; j++) {
				if(field[i][j] == '*') {
					dp[i][j] = 0;
				} else {
					dp[i][j] = min(dp[i-1][j], min(dp[i][j-1], dp[i-1][j-1])) + 1;
					ans = max(dp[i][j], ans);
				}
				
			}
		}
		return ans;
	}
	
	public static void main(String[] args) {
		while(read()) {
			System.out.println(solve());
		}
	}
}
