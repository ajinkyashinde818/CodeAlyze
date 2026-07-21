#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 1e5 + 100;

ll n, cnt, sum, a[N];

int main() {
	ios::sync_with_stdio(false), cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		cnt += (a[i] < 0);
		a[i] = fabs(a[i]);
		sum += a[i];
	}
	cout << (cnt & 1? sum - 2 * (*min_element(a, a + n)): sum);
	return 0;
}
