#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
	int n;
	cin>>n;

	vector<int> arr(n);
    ll mn = 1e10;
	int cnt = 0;
	ll res = 0;
	for(int i = 0; i < n; i++){
		ll t;cin>>t;
		if(t<0){
			cnt++;
			mn = min(mn,abs(t));
			res+=abs(t); 
		} else {
			res+=t;
			mn = min(mn,t);
		}
	}
	
	if(cnt%2) cout<<ll(res-2*mn);
	else cout<<res;
}
