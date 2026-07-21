#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long LL;
const int N = 2e5 + 10;

LL a[N];
LL sum[N];

int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i) cin >> a[i];
	for (int i = 1; i <= n; ++i) sum[i] = sum[i - 1] + a[i];

	LL minx = 1LL << 60;
	for (int i = 1; i < n; ++i) {
		LL tmp = abs(sum[i] - sum[n] + sum[i]);
		minx = min(minx, tmp);
	}

	cout << minx << endl;
}
