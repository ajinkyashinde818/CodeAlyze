#include <iostream>

using namespace std;

int main()
{
    int m, n;
	char a[50][50], b[50][50];
	bool flag2 = 0;
	
	cin >> n >> m;
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}
	
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++) {
			cin >> b[i][j];
		}
	}
	
	for (int i = 0; i <= n - m; i++) {
		for (int j = 0; j <= n - m; j++) {
			bool flag = 1;
			for (int k = 0; k < m; k++) {
				for (int l = 0; l < m; l++) {
					if (a[i+k][j+l] != b[k][l]) flag = 0;
				}
			}
			if (flag) flag2 = 1;
		}
	}
	
	if (flag2) {
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}
	
	return (0);
}
