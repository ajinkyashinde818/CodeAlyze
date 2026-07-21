#include<bits/stdc++.h>
using namespace std;

using ll=long long; 

ll mod=1e9+7;

void solve(){
	ll n;
	cin>>n;
	map<char, ll> cnt;
	string s;
	cin>>s;
	for(char c='a'; c<='z'; c=char(c+1)){
		cnt[c]=1;
	}
	for(int i=0; i<s.size(); i++){
		cnt[s[i]]++;
	}
	ll ans=1;
	for(char c='a'; c<='z'; c=char(c+1)){
		ans*=cnt[c];
		ans%=mod;
	}
	cout<<ans-1<<endl;
}

signed main(){
	//while(1)
	solve();
}
