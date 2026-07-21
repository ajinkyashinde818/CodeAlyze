import java.util.*;

public class Main{
	
	private void doit(){
		Scanner sc = new Scanner(System.in);
		while(true){
			int n = sc.nextInt();
			if(n == 0) break;
			char [][] c = new char[n][n];
			for(int i = 0; i < n; i++){
				c[i] = sc.next().toCharArray();
			}
			
			int [][] dp = new int[n][n];
			int max = 0;
			for(int i = 0; i < n; i++){
				for(int j = 0; j < n; j++){
					if(c[i][j] == '*') continue;
					dp[i][j] = 1 << 24;
					if(i - 1 >= 0){
						dp[i][j] = Math.min(dp[i][j], dp[i-1][j]);
					}
					else{
						dp[i][j] = 0;
					}
					if(j - 1 >= 0){
						dp[i][j] = Math.min(dp[i][j], dp[i][j-1]);
					}
					else{
						dp[i][j] = 0;
					}
					
					if(j - 1 >= 0 && i - 1 >= 0){
						dp[i][j] = Math.min(dp[i][j], dp[i-1][j-1]);
					}
					else{
						dp[i][j] = 0;
					}
					if(dp[i][j] == 1 << 24) dp[i][j] = 0;
					dp[i][j]++;
					max = Math.max(dp[i][j], max);
				}
			}
			System.out.println(max);
		}
	}
	
	public static void main(String[] args) {
		new Main().doit();
	}
}
