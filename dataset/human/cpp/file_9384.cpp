#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	
	int n, m;
	vector< vector<int> > a;
	vector< vector<int> > b;
	char tmp;

	cin >> n >> m;

	for (int i = 0; i < n; ++i) {
		a.resize(n);
		for (int j = 0; j < n; ++j) {
			cin >> tmp;
			if (tmp == '#') {
				a[i].push_back(0);
			}
			else {
				a[i].push_back(1);
			}
		}
	}

	for (int i = 0; i < m; ++i) {
		b.resize(m);
		for (int j = 0; j < m; ++j) {
			cin >> tmp;
			if (tmp == '#') {
				b[i].push_back(0);
			}
			else {
				b[i].push_back(1);
			}
		}
	}

	int f;

	for (int i = 0; i < n-m+1; ++i) {
		for (int j = 0; j < n-m+1; ++j) {
			f = 1;
			for (int k = 0; k < m; ++k) {
				for (int l = 0; l < m; ++l) {
					if (a[i+k][j+l] == b[k][l] ) {
						if (k == m - 1 && l == m - 1 && f == 1) {
							cout << "Yes" << endl;
							return 0;
						}
					}
					else {
						f = 0;
					}
				}
			}
		}
	}

	cout << "No" << endl;

}
