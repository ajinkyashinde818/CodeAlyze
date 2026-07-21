#include <iostream>
#include <string>
using namespace std;

int main() {
	
	// input
	int n, m;
	cin >> n >> m;
	
	string image [n];
	string templ [m];
	
	for (int i = 0; i < n; i++) {
		cin >> image[i];
	}
	for (int i = 0; i < m; i++) {
		cin >> templ[i];
	}
	
	bool found = false;
	
	// horizontal
	for (int i = 0; i <= n-m; i++) {
		// vertical
		for (int j = 0; j <= n-m; j++) {
			// substring match
			if (image[i].substr(j,m) == templ[0]) {
				if (m == 1) found = true;
				// check the lines below
				for (int k = 1; k < m; k++) {
					if (image[i+k].substr(j,m) != templ[k]) break;
					if (k == m - 1) found = true;
				}
			}
			// no match - continue
		}
	}
	
	if (found) cout << "Yes";
	else cout << "No";
	return 0;
}
