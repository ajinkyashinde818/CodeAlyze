#include <iostream>
#include <string>
#include <cstdio>
using namespace std;


int main()
{
	int N, M;
	cin >> N >> M;
	char A[50][50], B[50][50];
	for (int ay = 0; ay < N; ay++)
		for (int ax = 0; ax < N; ax++)
			cin >> A[ay][ax];
	for (int by = 0; by < M; by++)
		for (int bx = 0; bx < M; bx++)
			cin >> B[by][bx];
	
	for (int i = 0; i <= N - M; i++)
	{
		for (int j = 0; j <= N - M; j++)
		{
			int match = 1;
			for (int ai = 0; ai < M; ai++)
			{
				for (int aj = 0; aj < M; aj++)
				{
					if (B[ai][aj] != A[i + ai][j + aj])
					{
						match = 0;
						break;
					}
				}
				if (match == 0)
					break;
			}
			if (match)
			{
				cout << "Yes" << endl;
				return 0;
			}
		}
	}
	cout << "No" << endl;
	return 0;
	
}
