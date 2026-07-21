#include <iostream>
#include <algorithm>

using namespace std;


int main()
{
	int n, m;
	char N[51][51], M[51][51];

	cin >> n >> m;

	for (int i = 0; i < n*n; i++) {
		cin >> N[i/n][i%n];
	}
	for (int i = 0; i < m*m; i++) {
		cin >> M[i/m][i%m];
	}

	int res = 0;
	for (int i = 0; i < n - m + 1; i++) {
		for (int j = 0; j < n - m + 1; j++) {
			int w = 1;
			for (int k = i; k < i+m; k++) {
				for (int l = j; l < j+m; l++) {
					if (N[k][l] != M[k-i][l-j]) {
						w = 0;
					}
				}
			}
			if (w == 1) {
				res = 1;
			}
		}
	}


	if (res == 1) {
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}

	return 0;
}
