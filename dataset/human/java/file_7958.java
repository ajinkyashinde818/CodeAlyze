import java.util.*;

public class Main{
	public static int[][][] dp;

	public static boolean[] primes(int n){
		boolean[] primes = new boolean[n+1];
		Arrays.fill(primes, true);
		primes[0] = primes[1] = false;
		for(int i=2;i<=n;i++){
			if(primes[i]){
				for(int j=i*2;j<=n;j+=i){
					primes[j] = false;
				}
			}
		}
		return primes;
	}

	public static int dfs(int i,int n,int k,ArrayList<Integer> p){
		if(n == 0){
			if(k == 0) return 1;
			else return 0;
		}
		else if(k == 0) return 0;
		if(dp[i][n][k] != -1) return dp[i][n][k];

		int res = 0;
		for(int j=i;p.get(j)<=n;j++){
			res += dfs(j+1,n-p.get(j),k-1,p);
		}
		return dp[i][n][k] = res;
	}

	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);

		boolean[] flg = primes(1200);
		ArrayList<Integer> p = new ArrayList<Integer>();
		for(int i=0;i<flg.length;i++) if(flg[i]) p.add(i);

		int size = p.size();
		dp = new int[size][1121][15];
		for(int i=0;i<size;i++) for(int j=0;j<1121;j++) for(int k=0;k<15;k++) dp[i][j][k] = -1;

		while(true){
			int n=sc.nextInt(), k=sc.nextInt();
			if(n==0 && k==0) break;
			System.out.println(dfs(0,n,k,p));
		}
	}
}
