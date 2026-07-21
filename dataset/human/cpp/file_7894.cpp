#include<iostream>
#include<cstdio>
//#include<cmath>
using namespace std;

long long a[200101],ans=1e17,v1,v2,n,sum;

long long abss(long long x,long long y)
{
	if(v1>v2)
		return v1-v2;
	return v2-v1;
}

int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		sum+=a[i];
	}
	v1=a[1];
	v2=sum-a[1];
	ans=min(ans,abss(v2,v1));
	for(int i=2;i<n;i++)
	{
		v1+=a[i];
		v2-=a[i];
		ans=min(ans,abss(v2,v1));
	}
	cout<<ans<<endl;
	return 0;
}
