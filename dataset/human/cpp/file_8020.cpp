#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout<<setprecision(32);

	int n; cin>>n;
	vector<ll> a(n);
	for(auto &x : a){
		cin>>x;
	}
	ll sum = accumulate(a.begin(), a.end(), 0LL);
	ll cur = 0, ans = 1e18;
	for(int i = 0; i + 1 < n; i++){
		cur += a[i]; sum -= a[i];
		ans = min(ans, abs(sum - cur));
	}
	cout<<ans<<endl;


	return 0;
}
