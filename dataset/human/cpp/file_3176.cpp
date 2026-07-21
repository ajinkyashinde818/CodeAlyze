#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	int N;
	cin >> N;
	vector<long long> pos, zero, neg;
	long long ans = 0;
	for (int i = 0; i < N; ++i) {
		int x;
		cin >> x;
		if (x > 0) pos.push_back(x);
		else if (x < 0) neg.push_back(x);
		else zero.push_back(x);
		ans += (x > 0 ? x : -x);
	}
	if (zero.size() >= 1 || neg.size() % 2 == 0) {
		cout << ans << endl;
	}
	else {
		long long mn = 1LL << 60;
		if (!pos.empty()) mn = min(mn, *min_element(pos.begin(), pos.end()));
		if (!neg.empty()) mn = min(mn, -*max_element(neg.begin(), neg.end()));
		cout << ans - mn * 2 << endl;
	}
	return 0;
}
