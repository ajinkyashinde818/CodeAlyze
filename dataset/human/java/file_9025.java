import java.util.ArrayList;
import java.util.Scanner;

public class Main {
	public static void main(String[]args) {
		try(Scanner scan = new Scanner(System.in)){
			long mod = (long)1e9+7;
			int N = scan.nextInt();
			int M = scan.nextInt();
			int[]a = new int[M];
			int[]s = new int [N];
			for(int i = 0;i<M;i++) {
				a[i] = scan.nextInt();
				s[a[i]-1]++;
			}
			ArrayList<Integer>sb = new ArrayList<Integer>();
			
			for(int i = 0;i<N-1;i++) {
				if(s[i]==1&&s[i+1]==1) {
					System.out.println(0);
					System.exit(0);
				}
			}
			
			int count = 1;
			for(int i = 0;i<N;i++) {
				if(s[i]==1&&count!=0) {
					sb.add(count-1);
					count=0;
				}else if(s[i]==0) {
					count++;
				}
				if(i==N-1) {
					sb.add(count-1);
				}
			}
			COMinit();
			long goukei = 1;
			
			for(Integer i:sb) {
				//System.out.println(i);
				if(i==0)continue;
				int k = i/2;
				long sum = 0;
				for(int j = 0;j<=k;j++) {
					sum = (sum+COM(i-j,j))%mod;
					//System.out.println(COM(i-j,j));
				}
				
				goukei = (goukei*sum)%mod;
			}
			//System.out.println();
			System.out.println(goukei);
			
			
			
			
		}
		
		
	}
	
	
	//拡張ユークリッドでの逆元の求め方でnCkをつくる、前処理必須。
	
	static  int MAX = 510000;
	static  int MOD = 1000000007;

	 static long[] fac = new long[MAX]; 
	 static long[] finv = new long[MAX]; 
	 static long[] inv = new long[MAX]; 

	// テーブルを作る前処理
	static void COMinit() {
	    fac[0] = fac[1] = 1;
	    finv[0] = finv[1] = 1;
	    inv[1] = 1;
	    for (int i = 2; i < MAX; i++){
	        fac[i] = fac[i - 1] * i % MOD;
	        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
	        finv[i] = finv[i - 1] * inv[i] % MOD;
	    }
	}

	// 二項係数計算
	static long COM(int n, int k){
	    if (n < k) return 0;
	    if (n < 0 || k < 0) return 0;
	    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
	}
		

}
