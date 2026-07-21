#include<bits/stdc++.h>
using namespace std;
int a[200000], b[200000];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = n - 1; i >= 0; i--) {
		cin >> b[i];
	}
	int lbound = -1, ubound = -1;
	for (int i = 0; i < n; i++) {
		if (a[i] == b[i]) {
			lbound = i;
			int j;
			for (j = i + 1; j < n && a[j] == b[j]; j++);
			ubound = j;	
			break;
		}
	}
	if (lbound == -1) {
		cout << "Yes\n";
		for (int i = 0; i < n; i++) {
			cout << b[i] << ' ';
		}
		cout << '\n';
		return 0;
	}
	int share = a[lbound];
	int k = 0;
	int miss = 0;
	while (miss < n && lbound < ubound) {
		if (a[k] != share && b[k] != share) {
			b[lbound++] = b[k];
			b[k] = share;
			miss = 0;
		}
		k = (k + 1) % n;	
		miss++;
	}
	if (miss < n) {
		cout << "Yes\n";
		for (int i = 0; i < n; i++) {
			cout << b[i] << ' ';
		}
		cout << '\n';
	} else {
		cout << "No\n";
	}
	return 0;
}
