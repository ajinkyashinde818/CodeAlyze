#include<iostream>
#include<vector>
#include<algorithm>
#include<complex>
#include<string.h>
#include<string>
using namespace std;
typedef long long int llint;
int main() {
	int n, m;
	cin >> n >> m;
	char a[51][51], b[51][51];
	for (int i = 0;i < n;i++) {
		cin >> a[i];
	}
	for (int i = 0;i < m;i++) {
		cin >> b[i];
	}
	for (int i = 0;i <= n - m;i++) {
		for (int j = 0;j <= n - m;j++) {
			for (int k = 0;k < m;k++) {
				if (strncmp(a[i + k] + j, b[k], m) != 0) {
					break;
				}
				if (k == m - 1) {
					cout << "Yes" << endl;
					return 0;
				}
			}
		}
	}
	cout << "No" << endl;
	return 0;
}
