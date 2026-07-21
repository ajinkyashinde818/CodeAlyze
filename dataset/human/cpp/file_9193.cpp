#include <iostream>
#include <vector>

using namespace std;

int main() {
	int N, M;
	cin >> N >> M;
	vector<string> A(N), B(M);
	for(int i = 0; i < N; i++) cin >> A[i];
	for(int i = 0; i < M; i++) cin >> B[i];
	for(int dy = 0; dy <= N - M; dy++) {
		for(int dx = 0; dx <= N - M; dx++) {
			bool flag = true;
			for(int i = 0; i < M; i++) {
				for(int j = 0; j < M; j++) {
					int y = i + dy;
					int x = j + dx;
					if (A[y][x] != B[i][j]) {
						flag = false;
					}
				}
			}
			if (flag) {
				cout << "Yes" << endl;
				return 0;
			}
		}
	}
	cout << "No" << endl;
	return 0;
}
