import java.util.*;

public class Main{

	static int p[];
	static int c[];
	static int d, g;
	static int max = 0;
	static int dp[];	
	
	public static int solve(int k){
		int count = 0, sum = 0;
		if(k == d) {
			int tmp = -1;
			for(int i = 0; i < d; ++i){
				if(dp[i] == -1)tmp = i;
				else {
					sum += p[i] * (i + 1) + c[i] / 100;
					count += p[i];
				}
			}
			if(tmp == -1){
				if(sum < g / 100)return max;
				else return 0;
			}
			int tmp2 = (g / 100 - sum + tmp) / (tmp + 1);		
			if(tmp2 <= p[tmp] - 1){
				if(tmp2 <= 0)tmp2 = 0;
				count = tmp2;
				if(tmp == -1)count = 0;
			}
			else count = max;
			return count;
		}
		dp[k] = 1;
		count = p[k] + solve(k + 1);
		dp[k] = -1;
		count = Math.min(solve(k + 1), count);
		return count;
	}

	public static void main(String args[]){
		Scanner sc = new Scanner(System.in);
		d = sc.nextInt();
		g = sc.nextInt();
		p = new int[d];
		c = new int[d];
		dp = new int[d];
		for(int i = 0; i < d; ++i){
			p[i] = sc.nextInt();
			c[i] = sc.nextInt();
			max += p[i];
		}
		sc.close();
		int ans = solve(0);
		System.out.println(ans);
	}
}
