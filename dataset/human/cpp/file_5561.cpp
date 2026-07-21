#include<bits/stdc++.h>

using namespace std;

typedef long long ll;


void solve()
{
	ll n,r;
	cin>>n>>r;
	if(n>=10)
		cout<<r<<endl;
	else
	{
		ll x=r+100*(10-n);
		cout<<x<<endl;
	}
	return;
}
int main()
{
	ll t=1;
	//cin>>t;
	while(t--)
	{
		solve();
	}

	return 0;
}
