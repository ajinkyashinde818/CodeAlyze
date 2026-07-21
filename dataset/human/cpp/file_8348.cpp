#include "bits/stdc++.h"
using namespace std;

int main() {
	int N, M;
	cin >> N >> M;
	vector<string> A(N);
	vector<string> B(M);
	for (int n = 0; n < N; ++n) {
		cin >> A[n];
	}
	for (int n = 0; n < M; ++n) {
		cin >> B[n];
	}
	int ans = 0;
	for (int n = 0; n <= N - M; ++n) {
		for (int m = 0; m <= N - M; ++m) {
			bool b = true;
			for (int i = 0; i < M; ++i) {
				for (int j = 0; j < M; ++j) {
					if (A[i + n][j + m] != B[i][j]) {
						b = false;
					}
				}
			}
			if (b) {
				cout << "Yes" << endl;
				return 0;
			}
		}
	}
	cout << "No" << endl;
	return 0;
}
