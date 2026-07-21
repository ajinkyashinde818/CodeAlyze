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
constexpr ll MOD_LL = ll(1e9 + 7);

int main(void) {
	int n;
	cin >> n;
	
	vector<ll> a(n);
	for(int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	
	vector<ll> fsum(n + 1, 0), bsum(n + 1, 0);
	for(int i = 0; i < n; ++i) {
		fsum[i + 1] = fsum[i] + a[i];
		bsum[i + 1] = bsum[i] + a[n - i - 1];
	}
	
	
	ll ans = 1LL << 61;
	for(int i = 0; i < n + 1; ++i) {
		if( i == 0 || i == n ) continue;
		
		ans = min(ans, abs(fsum[i] - bsum[n - i]));
	}
	
	cout << ans << endl;
	
	return 0;
}
