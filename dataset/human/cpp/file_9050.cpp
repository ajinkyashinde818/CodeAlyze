#include <bits/stdc++.h>
using namespace std;

int main()
{
	int N, M;
	cin >> N >> M;
	vector<string> A(N), B(M);
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	for (int i = 0; i < M; i++) {
		cin >> B[i];
	}
	bool res = false;
	for (int i = 0; i + M <= N; i++) {
		for (int j = 0; j + M <= N; j++) {
			bool f = true;
			for (int k = 0; k < M; k++) {
				for (int l = 0; l < M; l++) {
					if (B[k][l] != A[i + k][j + l]) {
						f = false;
					}
				}
			}
			if (f) {
				res = true;
			}
		}
	}
	cout << (res ? "Yes" : "No") << endl;
	return 0;
}
