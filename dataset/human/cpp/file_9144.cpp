#include<iostream>
using namespace std;
int main() {
	int n, m;
	cin >> n >> m;
	
	char s[55][55];
	char t[55][55];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> s[i][j];
		}
	}

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++) {
			cin >> t[i][j];
		}
	}
	
	for (int a = 0; a < n - m + 1; a++) {
		for (int b = 0; b < n - m + 1; b++) {
			bool flag = true;
			for (int i = 0; i < m; i++) {
				for (int j = 0; j < m; j++) {
					if (s[i + a][j + b] != t[i][j]) {
						flag = false;
						
					}
					
				}
			}	
			if (flag) {
				cout << "Yes" << endl;
				return 0;
			}
		}
	}
	cout << "No" << endl;
	return 0;
}
