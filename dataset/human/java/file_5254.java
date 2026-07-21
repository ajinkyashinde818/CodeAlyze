import java.util.*;

class Main{
	public static void main(String args[]){
		Scanner s=new Scanner(System.in);
		while(true){
			int a=s.nextInt();
			if(a==0)System.exit(0);
			String [] b=new String[a];
			for(int i=0;i<a;i++){
				b[i]=s.next();
			}
			int [][] dp=new int[a][a];
			int ans=0;
			for(int i=0;i<a;i++){
				for(int j=0;j<a;j++){
					if(b[i].charAt(j)=='*')dp[i][j]=0;
					else{
						
						if(i==0||j==0)dp[i][j]=1;
						else{
							int now=1000;
							now=Math.min(now,Math.min(dp[i-1][j-1],Math.min(dp[i][j-1],dp[i-1][j])));
							dp[i][j]=now+1;
						}
						ans=Math.max(dp[i][j],ans);
					}
				}
			}
			System.out.println(ans);
		}
	}
}
