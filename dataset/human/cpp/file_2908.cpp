#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9+7;

int main(){
	
	int n; cin>>n;
	ll sum{};
	int m = 1e9;
	bool p{};
	for(int i=0; i<n; i++){
		int a; cin>>a;
		if(a<0) p^=1;
		sum += abs(a);
		m = min(m,abs(a));
	}
	if(p) sum -= 2*m;
	cout << sum << endl;
	
}
