#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	int i, j, n, m;
	//int ok = 1;
	char a[50][51];
	char b[50][51];
	
	cin >> n;
	cin >> m;
	for (i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (j = 0; j < m; j++) {
		cin >> b[j];
	}
	for (i = 0; i <= n - m; i++) {
		for (j = 0; j <= n - m; j++) {
			int ok = 1;
			for (int k = 0; k < m; k++) {
				string stra(a[i + k] + j, a[i + k] + j + m);
				string strb(b[k]);
				if (stra != strb) {
					ok = 0;
					break;
				}
			}
			if (ok == 1) {
				cout << "Yes" << endl;
				return (0);
			}
		}
	}
	cout << "No" << endl;
	return (0);
}
