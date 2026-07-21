#include <stdio.h>
#define mod 998244353
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define ll long long
ll C[4005][4005];
int n,k;
int main()
{
	for (int i=0;i<=4000;i++)
	{
		C[i][0]=1;
		for (int j=1;j<=i;j++) C[i][j]=(C[i-1][j-1]+C[i-1][j])%mod;
	}
	scanf("%d%d",&k,&n);
	for (int i=2;i<=k<<1;i++)
	{
		ll ans=0,cur=1;
		int cnt=max(min(i>>1,k)-max(i-k,1)+1,0),x=k-(cnt<<1);
		for (int j=0;j<=cnt;j++)
		{
			(ans+=C[cnt][j]*cur%mod*C[n+x-1][x+j-1])%=mod;
			cur=cur*2%mod;
		}
		printf("%lld\n",ans);
	}
	return 0;
}
