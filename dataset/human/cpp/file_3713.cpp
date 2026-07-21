#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
int n;
long long a[100005],sum,ans;
int main()
{
	scanf("%d",&n);for(int i=1;i<=n;++i) scanf("%lld",&a[i]);
	for(int i=1;i<=n;++i) if(a[i]<=0) ++sum;
	if(sum%2==0) {
		for(int i=1;i<=n;++i) ans+=abs(a[i]);
	}
	else {
		long long minn=1000000000;
		for(int i=1;i<=n;++i) minn=min(minn,abs(a[i]));
		for(int i=1;i<=n;++i) ans+=abs(a[i]);
		ans-=minn*2;
	}
	printf("%lld",ans);
	return 0;
}
