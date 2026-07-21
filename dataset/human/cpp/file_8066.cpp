#include<iostream>
#include<algorithm>
#include<string>
#include<functional>
#include<utility>
#include<stack>
#include<queue>
#include<cmath>
#include<list>
#include<cstdint>
#include<vector>
#include<map>
#include<deque>
#define rep(i,rept)	for(ll i = 0; i<(ll)rept;++i)
typedef long long ll;
using namespace std;


int main() {
	//22日目 
	ll n = 0, F = 0;
	vector<ll> a;
	ll sum = 0;
	cin >> n;
	rep(i, n) {
		cin >> F;
		a.push_back(F);
		sum += F;
	}

	ll umaru = 0, d = 0;
	d = 9223372036854775807;
	rep(i, n) {
		umaru += a[i];
		if(i+1<n)
		d = min(d,abs(sum-2*umaru));
	}
	cout << d << endl;
	return 0;
}
