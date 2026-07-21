#include <bits/stdc++.h>

using namespace std;

int main() {

	long n,m;
	cin >> n >> m;

	vector<string> a(n);
	vector<string> b(m);

	for (long i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (long i = 0; i < m; i++) {
		cin >> b[i];
	}

	bool fflg = false;
	for (long i = 0; i < n - m+1; i++) {
		for(long j=0;j<n-m+1;j++){
			if (a[i].substr(j, m) == b[0]) {
				for (long k = 0; k < m; k++) {
					if (a[i + k].substr(j, m) != b[k]) {
						break;
					}
					if (k == m-1) {
						cout << "Yes" << endl;
						return 0;
					}
				}
			}
		}
	}

	cout << "No" << endl;
}
