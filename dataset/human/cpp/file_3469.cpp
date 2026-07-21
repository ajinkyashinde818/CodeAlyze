#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <string>
#include <bitset>
#include <utility>
#include <numeric>
#include <queue>
#include <stack>

using ll = long long;
using namespace std;

constexpr int MOD = 1e9 + 7;
constexpr ll MOD_LL = ll(1e9) + 7;

int main(void) {
	int n;
	cin >> n;
	
	ll ans = 0LL;
	ll mini = MOD_LL;
	int minus = 0;
	
	for(int i = 0; i < n; ++i) {
		ll a;
		cin >> a;
		ans += abs(a);
		mini = min(mini, abs(a));
		
		if( a < 0 ) minus++;
	}
	
	if( minus % 2 == 0 ) {
		cout << ans << endl;
	} else {
		cout << ans - 2LL * mini << endl;
	}
	
	return 0;
}
