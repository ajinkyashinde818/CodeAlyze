#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
long long a[200001];
int main()
{
	long long n,t1=0,t2=0,t,ans=9999999999;
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]),t1+=a[i];
	for(int i=1;i<n;i++)
	{
		t1-=a[i];
		t2+=a[i];
		t=abs(t1-t2);
		ans=min(t,ans);
	}
	printf("%lld",ans);
}
