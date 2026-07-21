#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	long long a[n],cnt=0LL,mi=1000000000000LL,ans=0LL,f=0LL;
	for (int i = 0; i < n; ++i)
	{
		cin>>a[i];
		if (a[i]==0LL)
		{
			f=1LL;
		}
		else if (a[i]<0LL)
		{
			a[i]*=-1LL;
			++cnt;
		}
		ans+=a[i];
		mi=min(mi,a[i]);
	}
	if (f==1LL||cnt%2LL==0LL)
	{
		cout<<ans<<endl;
	}
	else
	{
		cout<<ans-2LL*mi<<endl;
	}
	return 0;
}
