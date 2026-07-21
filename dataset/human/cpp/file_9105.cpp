#include "iostream"
#include "algorithm"
#include "string"
#include "vector"
#include "cmath"
using namespace std;

int main() {
	int n, m;
	string a[50], b[50];
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < m; i++)
		cin >> b[i];
	bool flag;
	for (int i = 0; i <= n - m; i++) 
		for (int j = 0; j <= n - m; j++) {
			flag = false;
			for (int k = 0; k < m; k++) {
				for (int l = 0; l < m; l++) {
					if (a[i + k][j + l] != b[k][l]) {
						flag = true;
						break;
					}
				}
				if (flag == true)break;
			}
			if (flag != true) {
				cout << "Yes" << endl;
				return 0;
			}
		}
	cout << "No" << endl;
	return 0;
}
