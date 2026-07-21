#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
	int N, M;
	cin >> N >> M;
	vector<string> A(N);
	for (int i = 0; i < N; i++) cin >> A[i];
	vector<string> B(M);
	for (int i = 0; i < M; i++) cin >> B[i];

	for (int i = 0; i <= N - M; i++) {
		for (int j = 0; j <= N - M; j++) {
			bool match = true;
			for (int k = 0; k < M; k++) {
				if (A[i+k].substr(j, M) != B[k]) {
					match = false;
					break;
				}
			}
			if (match) {
				cout << "Yes" << endl;
				return 0;
			}
		}
	}
	cout << "No" << endl;
}
