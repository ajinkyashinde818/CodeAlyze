#include <bits/stdc++.h>
using namespace std;
int main()
{
	long long a,ans=0,minn=-1;
	int n,cnt=0,i;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&a);
		if(a<=0)
		{
			cnt++;
			a=-a;
		}
		ans+=a;
		if(minn==-1)
			minn=a;
		else
			minn=min(minn,a);
	}
	if(cnt%2==0)
		printf("%lld",ans);
	else
		printf("%lld",ans-2*minn);
    return 0;
}
