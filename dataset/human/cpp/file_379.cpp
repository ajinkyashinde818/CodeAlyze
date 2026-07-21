#include <iostream>
#include <string>
#include <algorithm>
#include <functional>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <cstdio>
#include <cmath>
using namespace std;

signed main() {
	int r, g, b, n;
	cin >> r >> g >> b >> n;
	
	int i, j;
	int ans = 0;
	for (i = 0; i <= n; i++) {
		for (j = 0; j <= n; j++) {
			int rem = n - r * i - g * j;
			if (rem < 0) continue;
			if (rem % b == 0) ans++;
		}
	}
	cout << ans << endl;
	return 0;
}
