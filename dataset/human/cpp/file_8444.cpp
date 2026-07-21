#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	int n, m;
	cin >> n >> m;
	vector<string>a(n);
	for (int i = 0; i < n; i++)cin >> a.at(i);
	vector<string>b(m);
	for (int i = 0; i < m; i++)cin >> b.at(i);
	for (int i = 0; i < n - m + 1; i++) {
		for (int j = 0; j < n - m + 1; j++) {
			bool ans = true;
			for (int k = 0; k < m; k++) {
				if (b.at(k) != a.at(k + i).substr(j, m))ans = false;
			}
			if (ans) {
				cout << "Yes" << endl;
				return 0;
			}
		}
	}
	cout << "No" << endl;
}
