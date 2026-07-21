#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
#include <map>
#include <unordered_map>
#include <set>
#include <functional>
using namespace std;

typedef long long ll;

ll x[100002], cal[100002];
ll suml[100002], sumr[100002];
ll mal[100002], mar[100002];

int main() {
	ll n, c; cin >> n >> c;
	for (int i = 1; i <= n; i++) {
		cin >> x[i] >> cal[i];
	}
	for (int i = 1; i <= n; i++) suml[i] = suml[i - 1] + cal[i];
	for (int i = n; i >= 1; i--) sumr[i] = sumr[i + 1] + cal[i];
	for (int i = 1; i <= n; i++) mal[i] = max(mal[i - 1], suml[i] - x[i]);
	for (int i = n; i >= 1; i--) mar[i] = max(mar[i + 1], sumr[i] - (c - x[i]));
	ll ans = max(mal[n], mar[1]);
	for (int i = 1; i <= n; i++) ans = max(ans, mal[i] + mar[i + 1] - x[i]);
	for (int i = n; i >= 1; i--) ans = max(ans, mar[i] + mal[i - 1] - (c - x[i]));
	cout << ans << endl;
	return 0;
}
