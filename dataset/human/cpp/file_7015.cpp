#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

void solve()
{
	ll n;
	cin>>n;
	ll freq1[n+1] = {},freq2[n+1] = {};
	ll a[n],b[n];
	ll f1 = -1, f2 = -3;
	for (int i = 0; i < n; ++i)
	{
		// ll k;
		cin>>a[i];
		freq1[a[i]]++;
		if(freq1[a[i]]*2>n)
			f1 = a[i];
	}
	for (int i = 0; i < n; ++i)
	{
		// ll k;
		cin>>b[i];
		freq2[b[i]]++;
		if(freq2[b[i]]*2>n)
			f2 = b[i];
	}
	if(f1==f2)
	{
		// cout<<f1<<f2<<endl;
		cout<<"No"<<endl;
		return;
	}
	sort(b,b+n,greater<ll>());
	ll k = 0;
	for (int i = 1; i < n; ++i)
	{
		if(a[i]==b[i])
		{
			ll prev = k;
			while(a[k]==b[i]||a[i]==b[k])
			{
				k++;
				k %= n;
				if(k==prev)
				{
					cout<<"No"<<endl;
					return;
				}
			}
			swap(b[k],b[i]);
			k++;
			k %= n;
		}
	}
	for (int i = 0; i < n; ++i)
	{
		if(a[i]==b[i])
		{
			cout<<"No"<<endl;
			return;
		}
	}
	cout<<"Yes"<<endl;
	for (int i = 0; i < n; ++i)
	{
		cout<<b[i]<<" ";
	}
	cout<<endl;
}

int main()
{
	ll t = 1;
	// cin>>t;
	while(t--)
	{
		solve();
	}
}
