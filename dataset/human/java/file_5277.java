import java.util.*;
public class Main {
	static Scanner sc = new Scanner(System.in);
	static char[][] field;
	static int[][] dp; 
	static int n;

	public static void main(String[] args) {
		while(read()){
			slove();
		}

	}
	static boolean read(){
		n = sc.nextInt();
		if(n == 0)
			return false;
		field = new char[n+1][n+1];
		dp = new int[n+1][n+1];
		String line;
		for(int i = 1; i <= n; i++){
			line = sc.next();
			for(int j = 1; j <= n; j++){
				field[i][j] = line.charAt(j-1);
				dp[i][j] = 0;
			}
		}
		for(int k = 1; k <= n; k++){
			dp[k][0] = 1;
			dp[0][k] = 1;
			}
		return true;
	}
	static int min(int a, int b, int c){
		int temp = Math.min(a, b);
		int min = Math.min(c, temp);
		return min;
	}
	static void slove(){
		int maxWidth = 0;
		int count = 0;
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++){
				if(field[i][j] == '*'){
					dp[i][j] = 0;
				}else{
					dp[i][j] = min(dp[i-1][j-1], dp[i-1][j], dp[i][j-1])+1;
					maxWidth = Math.max(maxWidth, dp[i][j]);
				}
			}
		}
		System.out.println(maxWidth);
	}

}
