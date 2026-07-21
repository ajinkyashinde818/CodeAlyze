#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,cnt[30];
string s;
int main() {
	cin>>n>>s;
	for(int i=0;i<n;i++){
		ll num=s[i]-'a';
		cnt[num]++;
	}
	ll ans=1,mod=1e9+7;
	for(int i=0;i<26;i++){
		ans*=(cnt[i]+1);
		ans%=mod;
	}
	cout<<ans-1;
	return 0;
}
