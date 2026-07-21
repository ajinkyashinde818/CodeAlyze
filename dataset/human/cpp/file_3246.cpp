#include<bits/stdc++.h>
using namespace std;
int n;
long long a[101010],mn=1e10+11,ans,cnt;
int main()
{
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		mn=min(abs(a[i]),mn);
		if(a[i]<0)
		{
			cnt++;
		}
	}
	for(int i=0;i<n;i++)
	{
		if(a[i]<0)
		{
			mn=-mn;
			break;
		}
	}
	for(int i=0;i<n;i++)
	{
		ans+=abs(a[i]);
	}
	if(mn<0 && cnt%2)
	{
		ans+=mn*2;
	}
	cout<<ans<<endl;
	return 0;
}
