#include <bits/stdc++.h>
using namespace std;

int n, m;
string a[50], b[50];

int main() {
	bool isYes = 0;

	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < m; i++)
		cin >> b[i];
	for (int i = 0; i < n - m + 1; i++)
		for (int j = 0; j < n - m + 1; j++) {
			bool flag = 1;
			for (int k = 0; k < m; k++)
				for (int l = 0; l < m; l++)
					if (a[k + i][l + j] != b[k][l])
						flag = 0;
			if (flag)
				isYes = 1;
		}

	cout << (isYes ? "Yes" : "No") << endl;
}
