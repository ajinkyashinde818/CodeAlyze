#include "bits/stdc++.h"
using namespace std;
int main() {
	long long N;
	cin >> N;
	long long ans = 0;
	long long MIN = 10000000000;
	long long L = 0;
	vector<long long>A(N);
	for (long long i = 0; i < N; i++) {
		cin >> A.at(i);
		long long ABS = abs(A.at(i));
		ans += ABS;
		if (MIN > ABS) MIN = ABS;
		if (A.at(i) < 0) L++;
	}
	if (L % 2 != 0) cout << ans - MIN - MIN << endl;
	else cout << ans << endl;
}
