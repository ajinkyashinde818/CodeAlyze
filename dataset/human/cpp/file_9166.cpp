#include <string>
#include <iostream>

using namespace std;

int main()
{
	long long ans=1, i, j, k, l, m, n, N, M, cnt=0;
	string A[50], B[50];

	cin >> N >> M;
	for (i = 0; i < N; i++)
		cin >> A[i];
	for (i = 0; i < M; i++)
		cin >> B[i];

	int al, bl;
	al = A[0].length(); bl = B[0].length();

	for (i = 0; i < N - M + 1; i++) {
		for (j = 0; j < al - bl + 1; j++) {
			if (A[i][j] == B[0][0]) {
				cnt = 0;
				for (k = 0; k < bl; k++) {
					for (l = 0; l < M; l++) {
						if (A[i + l][j + k] == B[l][k])
							cnt++;
					}
				}
				if (cnt == bl*M) {
					cout << "Yes" << endl;
					return 0;
				}
			}
		}
	}

	cout << "No" << endl;

	return 0;
}
