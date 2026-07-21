#include "bits/stdc++.h"
using namespace std;
int main() {
	long long N, M;
	cin >> N >> M;
	vector<vector<char>>A(N, vector<char>(N)), B(M, vector<char>(M));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> A.at(i).at(j);
		}
	}
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < M; j++) {
			cin >> B.at(i).at(j);
		}
	}
	int L = N - M + 1;
	for (int i = 0; i < L; i++) {
		for (int j = 0; j < L; j++) {
			int num = 0;
			for (int k = 0; k < M; k++) {
				for (int l = 0; l < M; l++) {
					if (A.at(i + k).at(j + l) != B.at(k).at(l)) num++;
				}
			}
			if (num == 0) {
				cout << "Yes" << endl;
				return 0;
			}
		}
	}
	cout << "No" << endl;
}
