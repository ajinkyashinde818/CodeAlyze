#include <bits/stdc++.h>
using namespace std;

int main() {
	int n,co=0;
	long long ans = 0;
	cin >> n;
	vector<int> da(n),me(0);
	for (int i = 0;i < n;i++) {
		cin >> da[i];
		if (da[i] < 0)
			co++;
		if (da[i] < 0) {
			me.push_back(-da[i]);
			ans -= da[i];
		}
		else {
			me.push_back(da[i]);
			ans += da[i];
		}
	}
	sort(me.begin(), me.end());
	if (me.size() > 1) {
		if (co % 2 == 0)
			cout << ans << endl;
		else
			cout << (long long)ans - me[0]*2 << endl;
	}
	else
		cout << ans << endl;
}
