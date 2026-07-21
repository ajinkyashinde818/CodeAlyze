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
	ll R, G, B, N;
	cin >> R >> G >> B >> N;
	
	ll ans = 0LL;
	for(ll r = 0; r <= N; ++ r) {
		for(ll g = 0; g <= N; ++g) {
			ll b = (N - R * r - G * g) / B;
			
			if( b >= 0 && R * r + G * g + B * b == N ) {
				ans++;
			}
		}
	}
	
	cout << ans << endl;
	
	return 0;
}
