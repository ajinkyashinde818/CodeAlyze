#include<bits/stdc++.h>
using namespace std;
int a[200005];
long long b[200005];
int main()
{
	int n;long long sum=0;
	cin>>n;
	memset(b,0,sizeof(b));
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		sum+=a[i];
		if(i==0)
			b[i]=a[i];
		else
			b[i]=b[i-1]+a[i];
	}
	long long ans=2*1e14+1;
	for(int i=0;i<n-1;i++)
	{
		ans=min(ans,abs(sum-2*b[i]));
	}
	cout<<ans;
	return 0;
}
