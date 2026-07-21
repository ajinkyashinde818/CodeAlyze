#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<algorithm>
using namespace std;
const int N=100005;
typedef long long ll;

int n,v[N];
ll C,x[N],s[N],qz[N],hz[N];


int main()
{
	scanf("%d%lld",&n,&C);
	for (int i=1;i<=n;i++)
	{
		scanf("%lld%d",&x[i],&v[i]);
		s[i]=s[i-1]+v[i];
	}
	ll ans=0;
	for (int i=1;i<=n;i++) qz[i]=max(qz[i-1],s[i]-x[i]);//,printf("qz[%d]=%lld\n",i,qz[i]);
	for (int i=n;i>=1;i--) hz[i]=max(hz[i+1],s[n]-s[i-1]-(C-x[i]));//,printf("hz[%d]=%lld\n",i,hz[i]);
	ans=max(qz[n],hz[1]);
	
	for (int i=1;i<=n;i++)
	{
		ans=max(ans,s[i]-x[i]*2+hz[i+1]);
		ans=max(ans,(s[n]-s[i-1])-(C-x[i])*2+qz[i-1]);
	}
	printf("%lld\n",ans);
	return 0;
}
