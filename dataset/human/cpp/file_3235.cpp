#include<bits/stdc++.h>

using namespace std;
using ll = long long;


int main()
{
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; i++)cin >> a[i];
	int cnt = 0;
	ll ans = 0;
	for(int i = 0; i < n; i++) {
		if(a[i] < 0) {
			cnt++;
			a[i] *= -1;
		}
		ans += a[i];
	}
	cerr << ans << endl;

	if(cnt&1) {
		cout << ans - *min_element(a.begin(), a.end()) * 2 << endl;
	}else {
		cout << ans << endl;
	}

}
