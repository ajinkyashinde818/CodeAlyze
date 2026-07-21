#include<iostream>
#include<string>
using namespace std;

int main()
{
	int n, m;
	char a[50][50], b[50][50];
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}
	for (int i = 0; i < m; i++){
		for (int j = 0; j < m; j++) {
			cin >> b[i][j];
		}
	}
	bool exist = false;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if ((i + m - 1 >= n) || (j + m - 1 >= n)) continue;
			bool match = true;
			for (int k = 0; k < m; k++) {
				for (int l = 0; l < m; l++) {
					if (a[i + k][j + l] != b[k][l]) match = false;
				}
			}
			if (match) exist = true;
		}
	}
	if (exist) cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}
