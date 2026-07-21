#include <iostream>
#include <vector>
#include <string>
using namespace std;


int main() {
	int n, m;
	cin >> n >> m;
	vector<string> a(n), b(m);
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < m; i++) cin >> b[i];
	int lim = n - m + 1;
	for (int top = 0; top < lim; top++) {
		for (int left = 0; left < lim; left++) {
			bool inc = true;
			for (int h = 0; h < m; h++) {
				if (a[top + h].substr(left, m) != b[h]) {
					inc = false;
					break;
				}
			}
			if (inc) {
				cout << "Yes" << endl;
				return 0;
			}
		}
	}
	cout << "No" << endl;
}
