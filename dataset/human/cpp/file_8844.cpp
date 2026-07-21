#include<iostream>
using namespace std;

int main(void) {
	const int max = 50;
	int N, M;
	char A[max][max], B[max][max];

	cin >> N >> M;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> A[i][j];

	for (int i = 0; i < M; i++)
		for (int j = 0; j < M; j++)
			cin >> B[i][j];

	bool ans = false;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (i + M - 1 > N || j + M - 1>N) continue;

			bool match = true;
			for (int a = 0; a < M; a++) {
				for (int b = 0; b < M; b++) {
					if (A[i + a][j + b] != B[a][b]) match = false;
				}
			}
			if (match) ans = true;
		}
	}

	if (ans)
		cout << "Yes" << endl;
	else
		cout << "No" << endl;

	return 0;
}
