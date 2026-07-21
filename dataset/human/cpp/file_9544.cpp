#include <iostream>
#include <cstdio>
using namespace std;

int n, m;
string a[55], b[55];

bool f(int p, int q) {
	int i, j;
	for (i = 0; i < m; i++) {
		for (j = 0; j < m; j++) {
			if (a[p + i][q + j] != b[i][j]) return 0;
		}
	}
	return 1;
}

int main()
{
	int i, j;
	cin >> n >> m;
	for (i = 0; i < n; i++) cin >> a[i];
	for (i = 0; i < m; i++) cin >> b[i];
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			if (f(i, j)) {
				cout << "Yes" << endl;
				return 0;
			}
		}
	}
    cout << "No" << endl;
    return 0;
}
