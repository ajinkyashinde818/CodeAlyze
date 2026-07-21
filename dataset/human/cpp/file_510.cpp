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
#include <bitset>
#include <cassert>
using namespace std;
using ll = long long;


int main() {
	int r, g, b, n; cin >> r >> g >> b >> n;
	int ans = 0;
	for (int i = 0; i <= n + 2; i++) {
		for (int j = 0; j <= n + 2; j++) {
			int a = n - r*i - g*j;
			if (a >= 0 && a%b == 0) ans++;
		}
	}
	cout << ans << endl;
	return 0;
}
