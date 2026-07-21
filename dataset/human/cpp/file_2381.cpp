#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	long long n;
	cin >> n;
	vector<long long> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];

	long long cnt = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] < 0) {
			cnt++;
			a[i] = a[i] * -1;
		}
	}
	
	sort(a.begin(), a.end());
	long long res = 0;
	
	if (cnt % 2 != 0) {
		a[0] = a[0] * -1;
	}
	for (int i = 0; i < n; i++) {
		res += a[i];
	}
	cout << res << endl;
}
