#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <climits>
#include <cmath>
#include <utility>
#include <string>
#include <cstring>
#include <functional>

using namespace std;

const int maxn = 100002;

int n, minv = INT_MAX, cnt = 0;
long long ans = 0;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n;
	for (int i = 0; i < n; ++i) {
		int a;
		cin >> a;
		if (a < 0) {
			a = -a;
			++cnt;
		}

		minv = min(minv, a);
		ans += a;
	}

	if (cnt & 1)
		ans = ans - minv - minv;

	cout << ans << endl;

	return 0;
}
