#include <bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
 
int main(){
	ll ans = 0;
    ll r, g, b, n; cin >> r >> g >> b >> n;
	for(ll i = 0; i <= 3000; ++i){
		for(ll j = 0; j <= 3000; ++j){
			if(((n - i * r - j * g) % b == 0 && n - i * r - j * g > 0) || n - i * r - j * g == 0){
				ans++;
			}
		}
	}
	cout << ans;
    return 0;
}
