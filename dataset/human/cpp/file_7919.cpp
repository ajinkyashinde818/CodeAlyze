#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <functional>
#include <iomanip>
#include <bitset>
#include <numeric>
#include <queue>
#include <map>
#include <cstdint>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
const long long mod = 100000000007;
typedef long long int ll;
typedef pair<ll, ll> P;
const vector<int> di = { -1, 0, 1, 0 };
const vector<int> dj = { 0, 1, 0, -1 };
const double PI = 3.14159265358979323846;

int main() {

	ll n;
	cin >> n;
	vector<ll> a(n);
	ll sum_all = 0;
	vector<ll> sum_comulative(n);
	rep(i, n) {
		cin >> a.at(i);
		sum_all += a.at(i);
		sum_comulative.at(i) = sum_all;
	}
	ll ans = mod;
	rep(i, n - 1) {
		ll x = sum_comulative.at(i);
		ll y = sum_all - x;
		ans = min(ans, abs(x - y));
	}
	cout << ans << endl;
	return 0;
	
}
