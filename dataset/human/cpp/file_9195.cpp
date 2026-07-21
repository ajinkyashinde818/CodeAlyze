#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <iomanip>
#include <algorithm>
#include <sstream>
#include <string>
#include <math.h>
#include <set>
using namespace std;
 
int main() {
	ios::sync_with_stdio(false);
	int n,m;
	cin >> n >> m;
	int a[n][n],b[m][m];
	char d;
	for (int i=0;i<n;i++) {
		for (int j=0;j<n;j++) {
			cin >> d;
			if ( d == '.' ) a[i][j] = 1;
			else a[i][j] = 0;
		}
	}
	for (int i=0;i<m;i++) {
		for (int j=0;j<m;j++) {
			cin >> d;
			if ( d == '.' ) b[i][j] = 1;
			else b[i][j] = 0;
		}
	}
	if ( n == m ) {
		for (int i=0;i<n;i++) {
			for (int j=0;j<n;j++) {
				if (a[i][j]!=b[i][j]) {
					cout << "No\n";
					return 0;
				}
			}
		}
		cout << "Yes\n";
	} else {
		for (int i=0;i<n-m+1;i++) {
			for (int j=0;j<n-m+1;j++) {
				bool y=0;
				for (int k=0;k<m;k++) {
					for (int l=0;l<m;l++) {
						if ( b[k][l] != a[i+k][j+l] ) {
							y=1;
							break;
						}
					}
				}
				if ( y == 0 ) {
					cout << "Yes\n";
					return 0;
				}
			}
		}
		cout << "No\n";
	}
}
