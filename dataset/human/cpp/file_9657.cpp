#include <iostream>

using namespace std;

const int MAX_N = 51;

char A[MAX_N][MAX_N];
char B[MAX_N][MAX_N];

int main() {
	int N, M;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> A[i][j];
		}
	}
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < M; j++) {
			cin >> B[i][j];
		}
	}
	bool flag = false;
	for (int i = 0; i + M - 1 < N; i++) {
		for (int j = 0; j + M - 1 < N; j++) {
			bool temp = true;
			for (int x = 0; x < M; x++) {
				for (int y = 0 ; y < M; y++) {
					if (A[i + x][j + y] != B[x][y]) temp = false;
				}
			}
			if (temp) flag = true;
		}
	}
	if (flag) cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}
