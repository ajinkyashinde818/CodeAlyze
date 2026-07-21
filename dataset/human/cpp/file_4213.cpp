#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
const long long inf = 1LL << 61;
int main() {
	long long n;
	cin >> n;
	vector<int> v;
	while (n > 0) {
		v.push_back(n % 3);
		n /= 3;
	}
	long long ans = inf;
	for (int i = 1; i <= v.size(); ++i) {
		vector<long long> b(i);
		long long mul = 1;
		for (int j = 0; j < v.size(); ++j) {
			if (j < i) b[j] = v[j];
			else {
				mul *= 3;
				b[i - 1] += v[j] * mul;
			}
		}
		bool ok = true;
		for (int j = 0; j < i; ++j) {
			int limit = (j == 0 || j == i - 1 ? 1 : 2);
			if (b[j] >= limit) continue;
			bool found = false;
			for (int k = j + 1; k < i; ++k) {
				if (b[k] >= 1) {
					--b[k];
					for (int l = k - 1; l > j; --l) {
						b[l] += 2;
					}
					b[j] += 3;
					found = true;
					break;
				}
			}
			if (!found) {
				ok = false;
				break;
			}
		}
		if (ok) {
			long long sum = 0;
			for (int j = 0; j < i; ++j) {
				sum += b[j];
			}
			ans = min(ans, sum);
		}
	}
	if (v.empty()) cout << 0 << endl;
	else cout << ans << endl;
	return 0;
}
