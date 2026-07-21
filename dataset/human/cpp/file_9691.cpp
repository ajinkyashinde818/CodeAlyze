#include <iostream>
using namespace std;
int main() {
	char A[50][50];
	char B[50][50];
	bool can = false;
	int M, N;



	cin >> M >> N;
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> A[i][j];
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> B[i][j];
		}
	}

	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < M; j++)
		{
			bool flg = true;
			for (int x = 0; x < N; x++)
			{
				for (int y = 0; y < N; y++)
				{
					if (A[i + x][j + y] != B[x][y]) {
						flg = false;
					}
				}
			}
			if (flg) {
				can = true;
			}
		}
	}
	if (can) {
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}
	return 0;
}
