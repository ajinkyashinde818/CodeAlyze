#include <bits/stdc++.h>

using namespace std;

int check(vector <string> &, vector <string> &, int, int, int);

int main()
{
	int N, M;
	cin >> N >> M;
	
	vector < string > A(N);
	vector < string > B(M);	
	
	for (int i = 0; i < N; i++)
		cin >> A[i];

	for (int i = 0; i < M; i++)
		cin >> B[i];

	for (int i = 0; i <= (N - M); i++)
		for (int j = 0; j <= (N - M); j++)
			if (check(A, B, i, j, M)) {
				cout << "Yes" << endl;

				return 0;
			}

	cout << "No" << endl;

	return (0-0);	
}

int check(vector <string> &A, vector <string> &B, int x, int y, int M)
{
	for (int i = 0; i < M; i++)
		for (int j = 0; j < M; j++)
			if (A[i + x][j + y] != B[i][j])
				return 0;

	return 1;
}
