#include<bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int N, M;
	string A[50];
	string B[50];
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	for (int i = 0; i < M; i++) {
		cin >> B[i];
	}
	for (int i = 0; i < N-M+1; i++) {
		for (int j = 0; j < N-M+1; j++) {
			int s = 1;
			for (int k = 0; k < M; k++) {
				for (int l = 0; l < M; l++) {
					if (A[i + k][j + l] != B[k][l]) {
						s = 0;
					}
				}
			}
			if (s == 1) {
				cout << "Yes";
				return 0;
			}
		}
	}
	cout << "No";
}
