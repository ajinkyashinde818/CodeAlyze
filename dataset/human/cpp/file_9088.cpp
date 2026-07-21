#include <iostream>
#include <string>
#include <vector>
using namespace std;

int N, M;
vector<string> A, B;

int main(void) {
	cin >> N >> M;
	A.resize(N);
	B.resize(M);
	for (int j = 0; j < N; ++j)
		cin >> A[j];
	for (int j = 0; j < M; ++j)
		cin >> B[j];

	string ans = "No";
	for (int y = 0; y <= N - M; ++y) {
		for (int x = 0; x <= N - M; ++x) {
			ans = "Yes";
			for (int j = 0; j < M; ++j) {
				string subA = A[y + j].substr(x, M);
				if (B[j] != subA) {
					ans = "No";
					break;
				}
			}
			if (ans == "Yes")
				break;
		}
		if (ans == "Yes")
			break;
	}

	cout << ans << '\n';
	return 0;
}
