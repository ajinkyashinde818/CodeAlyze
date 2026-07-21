#include <iostream>
using namespace std;

int main(void)
{
	int M, N;
	char A[50][50], B[50][50];
	cin >> N >> M;
	int x = 0, y = 0;
	for (; y < N; ++y) {
		cin >> A[y];
	}
	for (y = 0; y < M; ++y) {
		cin >> B[y];
	}
	for (y = 0; y + M <= N; ++y) {
		for (x = 0; x + M <= N; ++x) {
			int count = 0;
			for (int i = 0; i < M; ++i) {
				for (int j = 0; j < M; ++j) {
					if (A[y + i][x + j] == B[i][j])++count;
				}
			}
			if (count == M*M) {
				cout << "Yes" << endl;
				return 0;
			}
		}
	}

	cout << "No" << endl;
	
	return 0;
}
