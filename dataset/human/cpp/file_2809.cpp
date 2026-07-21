#include <iostream>
#include <cstdio>
using namespace std;

typedef long long ll;
ll n, s, s2, cnt, mn = 1e10, a[100005];
int main()
{
	ll i;
	cin >> n;
	for (i = 0; i < n; i++) {
		scanf ("%lld", &a[i]);
		s += a[i];
		if (a[i] < 0) {
			cnt++;
			mn = min(mn, -a[i]);
			s2 += -a[i];
		} else {
			s2 += a[i];
			mn = min(mn, a[i]);
		}
	}
	if (cnt % 2 == 0) cout << s2 << endl;
	else cout << s2 - mn * 2;
    return 0;
}
