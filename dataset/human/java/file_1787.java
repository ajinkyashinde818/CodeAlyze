import java.util.*;

class Main{
	public static void main(String[]$){
		Scanner s=new Scanner(System.in);
		int n=s.nextInt(),g=s.nextInt()/100;
		int[]dp=new int[g+1];
		Arrays.fill(dp,1,g+1,9000);
		for(int i=1;i<=n;++i) {
			int m=s.nextInt(),b=s.nextInt()/100;
			for(int j=g-1;j>=0;--j) {
				for(int k=1;k<=m;++k) {
					int t=Math.min(g,j+k*i+(k<m?0:b));
					dp[t]=Math.min(dp[t],dp[j]+k);
					if(t==g)
						break;
				}
			}
		}
		System.out.println(dp[g]);
	}
}
