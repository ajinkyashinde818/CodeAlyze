#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
long long a[maxn];
int main()
{
	int n;
	scanf("%d",&n);
	int fu=0;
	long long sum=0;
	int flag=0;
	long long minn=0x3f3f3f3f;
	for(int i=1; i<=n; i++)
	{
		scanf("%lld",&a[i]);
		sum+=abs(a[i]);
		if(a[i]<0)
			fu++;
		if(a[i]==0)
			flag=1;
		if(a[i]==0)
			continue;
		minn=min(minn,abs(a[i]));
	}
	long long ans;
	if(flag||fu%2==0)
		ans=sum;
	else if(fu%2==1)
		ans=sum-minn*2;
//	printf("%lld %lld\n",sum,minn);
	printf("%lld",ans);
	

}
