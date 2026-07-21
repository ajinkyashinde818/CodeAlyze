#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <limits>
#include <numeric>
#include <set>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;

#define rep(i, N) for (int i = 0; i < N; i++)


int main()
{
	int n, m;
	cin >> n >> m;

	vector<string> a(n),b(m);
	for (int i = 0; i < n; i++)cin >> a[i];
	for (int i = 0; i < m; i++)cin >> b[i];

	bool flag = false;
	for (int i = 0; i < n - m + 1; i++) {
		for (int j = 0; j < n - m + 1; j++) {
			if (a[i].substr(j, m) == b[0]) {

				if (m == 1) {
					cout << "Yes" << endl;
					return 0;
				}

				for (int ii = 0; ii < m-1; ii++) {
					if (a[i + ii + 1].substr(j, m) != b[ii + 1]) break;
					else if (ii == m - 2) {
						cout << "Yes" << endl;
						return 0;
					}
				}
			}
		}
	}
	
	cout << "No" << endl;
	return 0;
}
