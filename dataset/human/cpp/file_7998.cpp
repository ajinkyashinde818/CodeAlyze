#include<stdio.h>
#include<algorithm>
using namespace std;
long long a[200005],sum[200005];
int main()
{
	int n;
	while(~scanf("%d",&n))
	{
		sum[0]=0;
		for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
		for(int i=1;i<=n;i++)sum[i]=sum[i-1]+a[i];
		long long minn=10000000000000000; 
		for(int i=2;i<=n;i++)
		{
			long long a=sum[i-1];
			long long b=sum[n]-sum[i-1];
			if(abs(a-b)<minn)minn=abs(a-b);
		}
		printf("%lld\n",minn);
	}
	return 0;
 }
