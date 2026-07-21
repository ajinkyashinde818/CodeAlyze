#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main () {
	ll ans = 0;
	int n; cin >> n;
	ll in[n];
	int neg = 0;
	for (int i = 0; i < n; i++) {
		cin >> in[i];
		if (in[i] < 0) neg++;
		in[i] = abs(in[i]);
	}

	sort(in,in+n);

	for (int i = 1; i < n; i++)
		ans += in[i];

	if (neg&1) ans -= in[0];
	else ans += in[0];

	cout << ans << endl;

	return 0;
}
