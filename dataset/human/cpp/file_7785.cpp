#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>
#include <iomanip>
using namespace std;
#define PI acos(-1)
typedef long long ll;
typedef pair<int, int> p_ii;
const ll INF = 1LL << 60;


int main() {
	
	ll sum = 0;
	int n;
	cin >> n;
	vector<ll> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		sum += a[i];
	}
	vector<ll> cum(n+1);
	cum[0] = 0;
	for (int i = 1; i <= n; i++)cum[i] += cum[i - 1] + a[i - 1];

	ll ans = INF;
	for (int i = 1; i < n; i++) ans = min(ans, abs(2 * (cum[i] - cum[0]) - sum));
	cout << ans << endl;

	return 0;
}
