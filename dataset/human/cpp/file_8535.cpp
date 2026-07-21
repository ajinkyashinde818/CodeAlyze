#include <cmath>
#include <iostream>
#include <stdio.h>
#include <string>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <set>
#include <limits.h>
#include <map>
#include <numeric>

namespace test {
	std::string to_string (char val) {
		return std::string (1, val);
		// return std::string{val};
	}
	//if( str.find ("r") != string::npos)
}

using namespace std;
typedef long long int llint;

bool f (char **a, char **b, int n, int m) {
	bool exist = true;

	int sideInterval = n - m;
	int yInterval = ( n / 2 - m > 0 ? n / 2 - m : 0 );
	for (int k = 0; k <= sideInterval; k++) {
		for (int g = 0; g <= yInterval; g++) {
			for (int i = k; i < k + m; i++) {
				for (int j = g; j < g + m; j++) {
					if (a[i][j] == b[i-k][j-g]) {
						continue;
					}
					else {
						exist = false;
						break;
					}
				}
				if(!exist) break;

			}
			if (exist) {
				return true;
			}
			exist = true;
		}
	}
	return false;
}

int main (void) {
	int n,m; cin >> n >> m;
	char **a = new char*[n];
	char **b = new char*[m];
	for (int i = 0; i < n; i++) {
		a[i] = new char[n];
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}

	for (int i = 0; i < m; i++) {
		b[i] = new char[m];
		for (int j = 0; j < m; j++) {
			cin >> b[i][j];
		}
	}

	cout << (f(a,b,n,m) ? "Yes" : "No" ) << endl;
	
	return 0;
}
