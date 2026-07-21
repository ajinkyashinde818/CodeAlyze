#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	
	ll N;
	ll t;
	ll ans = 0;
	ll first, last;
	ll b = 0;
	ll min;
	int z = 0;
	
	cin >> N;
	for(ll i=0; i<N; i++){
		cin >> t;
		
		if(t < 0) b++;
		else if(t == 0) z=1;
		
		t = abs(t);
		ans += t;
		if(i == 0) min = t;
		else min = (t < min) ? t : min;
	}
	
	if(b%2 != 0 && z == 0){
		ans -= (min * 2);
	}
	
	printf("%lld\n", ans);
	return 0;
	
}
