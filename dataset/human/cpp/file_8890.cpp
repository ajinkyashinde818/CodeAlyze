#include <iostream>
#include <limits.h>
using namespace std;

int beau = 1000000009;

int main() {
	int n, m, ms = 0;
	char a[55][55], b[55][55];
	bool ans = false;
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < m; i++) cin >> b[i];
	for (int i = 0; i < n - m + 1; i++) {
	    for (int j = 0; j < n - m + 1; j++) {
	        for (int k = 0; k < m; k++) {
	            for (int l = 0; l < m; l++) {
	                if (b[k][l] == a[i + k][j + l]) ms++;
	            }
	        }
	        if (ms == m * m) ans = true;
	        ms = 0;
	    }
	}
	if (ans) cout << "Yes";
	else cout << "No";
	return 0;
}
