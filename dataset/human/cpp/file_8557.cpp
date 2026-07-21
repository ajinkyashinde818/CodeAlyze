#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;
	vector<string> s(n), t(m);
	for (int i = 0; i < n; i++) {
		cin >> s[i];
	}
	for (int i = 0; i < m; i++) {
		cin >> t[i];
	}

	int tmp = 0;
	for (int i = 0; i < n - m + 1; i++) {
		for (int j = 0; j < n - m + 1; j++) {
			tmp = 0;
			for (int k = 0; k < m; k++) {
				for (int l = 0; l < m; l++) {
					if (s[i + k][j + l] == t[k][l]) {
						tmp++;
					}
				}
			}

			if (tmp == m * m) {
				cout << "Yes" << endl;

				return 0;
			}
		}
	}
	cout << "No" << endl;

	return 0;
}
