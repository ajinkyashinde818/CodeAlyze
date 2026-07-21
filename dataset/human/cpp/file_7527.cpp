#include"bits/stdc++.h"
using namespace std;
using ll=long long;
using vlli=vector<ll>::iterator;
void solve();
ll sum(ll,ll);

ll n;
vector<ll> a;
vector<ll> s;

int main(){
	solve();
	return 0;
}
void solve(){
	cin >>n;
	a.resize(n+1);
	s.resize(n+1);
	a[0]=0;
	s[0]=a[0];
	for(ll i=1;i<=n;i++){
		cin >>a[i];
		s[i]=s[i-1]+a[i];
	}
	
	ll ans=1e18;
	for(ll i=1;i<n;i++){
		ans=min(ans,abs(sum(1,i)-sum(i+1,n)));
	}
	cout <<ans <<endl;
}

ll sum(ll l,ll r){
	return s[r]-s[l-1];
}
