#include <bits/stdc++.h>
using namespace std;

const long long mod=1000000007;

int main(int argc, char const *argv[])
{
	int n;
	string s;
	cin>>n>>s;
	int cnt[30]={};
	for (int i = 0; i < n; ++i)
	{
		++cnt[s.at(i)-'a'];
	}
	long long ans=1LL;
	for (int i = 0; i < 30; ++i)
	{
		ans*=(long long)cnt[i]+1LL;
		ans%=mod;
	}
	ans+=mod-1LL;
	ans%=mod;
	cout<<ans<<endl;
	return 0;
}
