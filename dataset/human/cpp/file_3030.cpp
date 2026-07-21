#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long n,i,ans=0,minn=1e9,x,to=0;
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>x;
		ans+=abs(x);
		minn=min(minn,abs(x));
		if(x<0) to++;
		if(to==2) to=0;
	}
	if(!to) cout<<ans<<endl;
	else cout<<ans-2*minn<<endl;
	return 0;
}
