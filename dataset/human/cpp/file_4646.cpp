#include <bits/stdc++.h>
using namespace std;
const int maxx = 1e5 + 7;
typedef long long ll;
const int Inf = 1 << 30;
const ll INF = 1ll << 60;
int n, r;

int main() {
	cin >> n >> r;
	if(n >= 10) cout << r << endl;
	else {
		int ans = 100 * (10 - n) + r;
		cout << ans << endl;
	}
	return 0;
}
