#include <iostream>
#include <vector>
#include <numeric>
using namespace std;
int main(void) {
	int n;
	cin >> n;
	vector<long long> a(n);
	for (int i = 0; i < n; ++i) cin >> a[i];
	long long sum = accumulate(a.begin(), a.end(), 0LL);
	long long snuke = 0;
	long long ans = 1e18;
	for (int i = 0; i < n - 1; ++i) {
		snuke += a[i];
		long long kuma = sum - snuke;
		ans = min(ans, abs(snuke - kuma));
	}
	cout << ans << endl;
	return 0;
}
