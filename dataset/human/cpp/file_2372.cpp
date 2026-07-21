#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	ll n;
	cin >> n;
	vector<ll> A(n);
	for(ll i = 0;i<n;i++)cin >> A[i];
	ll cnt = 0;
	ll ans = 0;
	ll mn = INT_MAX;
	bool zero = false;
	for(auto i:A){ans += abs(i);if(i<0)cnt++;if(i==0)zero=true;mn =min(mn,abs(i));}
	//cout<<(cnt%2==0)<<';'<<zero<<endl;
	if(cnt%2==0||zero==true)
	{
		cout<<ans<<endl;
	}
	else
	{
		//cout<<ans<<endl;
		cout<<ans-mn*2<<endl;
	}
	return 0;
}
