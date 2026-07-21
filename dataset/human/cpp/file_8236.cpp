#include<cstdio>
using namespace std;
long long a[210000];
long long abs(long long x)
{
	return x<0?-x:x;
}
long long min(long long x,long long y)
{
	return x<y?x:y;
}
int main()
{
	int n;
	long long sum=0,ans;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		sum+=a[i];
	}
	ans=abs(a[1]*2-sum);
	long long s=a[1];
	for(int i=2;i<n;i++)
	{
		s+=a[i];
		ans=min(ans,abs(s*2-sum));
	}
	printf("%lld\n",ans);
	return 0;
}
