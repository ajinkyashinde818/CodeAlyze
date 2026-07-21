#include <iostream>

using namespace std;

int main() {
	const int max = 50;

	int N, M;
	char a[max][max],  b[max][max];
	bool ans = false;

	cin >> N >> M;
	for (int i = 0; i < N; i++)	cin >> a[i];
	for (int i = 0; i < M; i++)	cin >> b[i];

	for (int i = 0; i <= N - M; i++) {
		for (int j = 0; j <= N - M; j++) {
			for (int k = 0; k < M; k++) {
				for (int l = 0; l < M; l++) {
					if (a[i + k][j + l] != b[k][l])	goto OUT;
					if (k == M - 1 && l == M - 1) {
						ans = true;
						goto ANS;
					}
				}
			}
			OUT:;
		}
	}

	ANS:
	cout << ((ans) ? "Yes" : "No") << endl;

	return 0;
}
