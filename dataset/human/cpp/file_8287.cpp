#include <iostream>
#include <string> 
using namespace std;
int main() {
	string a[50], b[50];
	int N, M;
	bool flag = 0;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < M; i++) {
		cin >> b[i];
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (a[i][j] == b[0][0])flag = 1;
			if (flag == 1) {
				for (int ii = 0; ii < M; ii++) {
					for (int jj = 0; jj < M; jj++) {
						if (a[i + ii][jj + j] != b[ii][jj]) { flag = 0; break; }

					}
				}
			}
			if (flag == 1)break;
		}
		if (flag == 1)break;
	}

	if (flag == 1)cout << "Yes\n";
	else cout << "No\n";
	return 0;

}
