#include <iostream>
#include <algorithm>
using namespace std;

const int mxN = 2e5 + 5;
int a[mxN];

int main() {
	int n;
	cin >> n;
	int cnt = 0;
	bool zero = false;
	for(int i = 0; i < n; ++i) {
		cin >> a[i];
		cnt += a[i] < 0;
		zero |= a[i] == 0;
		a[i] = max(a[i], -a[i]);
	}
	if(zero) {
		long long tot = 0;
		for(int i = 0; i < n; ++i)
			tot += a[i];
		return cout << tot, 0;
	}
	sort(a, a + n);
	cnt %= 2;
	long long tot = cnt % 2 ? -a[0] : a[0];
	for(int i = 1; i < n; ++i)
		tot += a[i];
	cout << tot;
}
