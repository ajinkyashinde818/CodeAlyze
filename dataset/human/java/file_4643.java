import java.util.*;

public class Main{
	Scanner sc = new Scanner(System.in);
	int wid = 1500000;

	private void doit(){
		while(true){
			int m = sc.nextInt();
			int n = sc.nextInt();
			if((n|m) == 0) break;
			int [] data = new int[n];
			for(int i = 0 ; i < n; i++){
				data[i] = sc.nextInt();
			}
			int [] acc = new int[n];
			acc[0] = data[0];
			for(int i = 1 ; i < n; i++){
				acc[i] = acc[i-1] + data[i];
			}
			int [][] dp = new int[n][m];
			int INF = 1 << 24;
			for(int i = 0 ; i < n; i++){
				Arrays.fill(dp[i], INF);
			}
			for(int i = 0 ; i < n; i++){
				if(acc[i] >= wid) break;
				dp[i][0] =  acc[i];
			}
			
			for(int i = 0 ; i < m-1; i++){
				for(int j = 0; j < n; j++){
					if(dp[j][i] == INF) continue;
					for(int k = j + 1 ; k < n; k++){
						int value = Math.max(dp[j][i], acc[k] - acc[j]);
						if(value >= wid) continue;
						dp[k][i + 1] = Math.min(dp[k][i + 1], value);
					}
				}
			}
			int ans = INF;
			for(int i = 0 ; i < m; i++){
				ans = Math.min(dp[n-1][i], ans);
			}
			System.out.println(ans);
		}
	}
	

	private void debug(Object... o) { System.out.println("debug = " + Arrays.deepToString(o)); }

	public static void main(String[] args) {
		new Main().doit();
	}
}
