#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
#include<queue>
#include<cmath>
#include <numeric>
#include<iomanip>
#include <cstdint>
#include<deque>
typedef long long ll;

using namespace std;

int main() {
	int n;
	cin >> n;
	vector<ll>a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int count = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] < 0) {
			count++;
			a[i] *= (-1);
		}
	}
	ll ans = 0;
	sort(a.begin(), a.end());
	if (count % 2 != 0) {
		a[0] *= (-1);
	}
	for (int i = 0; i < n; i++) {
		ans += a[i];
	}
	cout << ans << endl;
}
