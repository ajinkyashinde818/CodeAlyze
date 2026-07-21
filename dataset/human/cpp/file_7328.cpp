#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int mod = 1e9+7;

int main(){
	std::ios::sync_with_stdio(false);
    cin.tie(0);
	int n;
	cin >> n;
	ll v[n+1],pf[n+1];
	memset(pf,0,sizeof(pf));
	for(int i=1;i<=n;i++){
		cin >> v[i];
		pf[i] += pf[i-1] + v[i];
	}
	ll ans = 2*1ll*INT_MAX;
	for(int i=1;i<=n-1;i++){
		ll ss = pf[i]-pf[0],rr = pf[n]-pf[i];
		ans = min(ans,abs(ss-rr));
	}
	cout << ans << "\n";

	return 0;
}
