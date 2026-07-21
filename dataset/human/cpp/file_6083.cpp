#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
const int N=100005;
int n,pos1,pos2; 
ll C,x[N],w[N],sum,Max,Max1[N],Max2[N];
int main()
{
	scanf("%d%lld",&n,&C);
	for (int i=1;i<=n;i++) scanf("%lld%lld",&x[i],&w[i]);
	for (int i=1;i<=n;i++) 
	  sum+=w[i],Max1[i]=max(Max1[i-1],sum-x[i]);
	sum=0;
	for (int i=n;i>=1;i--) 
	   sum+=w[i],Max2[i]=max(Max2[i+1],sum-(C-x[i]));
	Max=max(Max1[n],Max2[1]);
	sum=0;
	for (int i=1;i<=n;i++) sum+=w[i],Max=max(Max,Max2[i+1]+sum-x[i]*2); 
	sum=0;
	for (int i=n;i>=1;i--) sum+=w[i],Max=max(Max,Max1[i-1]+sum-(C-x[i])*2);
	printf("%lld\n",Max);
	return 0;
}
