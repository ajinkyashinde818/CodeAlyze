#include <bits/stdc++.h>
using namespace std;


//#define int long long 


const int N = 2e5 + 7;

int a[N], b[N];

int32_t main() {
	ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n; cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = 1; i <= n; i++) cin >> b[i];

	reverse(b + 1, b + n + 1);

	vector <int> x, y;

	int z = -1;
	for(int i = 1; i <= n; i++) {
		if(a[i] == b[i]) {
			z = b[i];
			x.push_back(i);
		}
	}

	for(int i = 1; i <= n && y.size() < x.size(); i++) if((a[i] ^ z) && (b[i] ^ z)) {
		y.push_back(i);
	}

	if(x.size() > y.size()) {
		cout << "No" << endl;
		return 0;
	}

	cout << "Yes" << endl;
	for(int i = 0; i < x.size(); i++) swap(b[x[i]], b[y[i]]);
	for(int i = 1; i <= n; i++) cout << b[i] << " \n"[i == n];
}
