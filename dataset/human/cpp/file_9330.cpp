#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<math.h>
using namespace std;
int main() {
	int N, M;	cin >> N >> M;
	vector<string> A(N);
	vector<string> B(M);
	int sameNUM;

	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	for (int i = 0; i < M; ++i) {
		cin >> B[i];
	}
	for (int i = 0; i <= N - M; ++i) {
		for (int j = 0; j <= N - M; ++j) {
			sameNUM = 0;
			for (int k = 0; k < M; ++k) {
				for (int l = 0; l < M; ++l) {
					if (A[i + k][j + l] == B[k][l]) {
						sameNUM++;
					}
				}
			}
			if (sameNUM == M*M) {
				cout << "Yes" << endl;
				cin >> N;
				return 0;
			}
		}
	}
	cout << "No" << endl;
	cin >> N;
}
