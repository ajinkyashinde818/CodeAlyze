#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(int, char**)
{
	ll n, num = 0, aal = 0, mn = 1000000001, ans = 0;
	cin >> n;

	for (unsigned int i = 0; i < n; ++i) {
		ll x;
		cin >> x;
		if (x >= 0) {
			aal += x;
			mn = min(mn, x);
		} else {
			num++;
			aal -= x;
			mn = min(mn, -x);
		}
	}

	if (num % 2 > 0)
		cout << (aal - mn - mn) << endl;
	else
		cout << aal << endl;

	return 0;
}
