#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;

int main()
{
	long long lnN, lnM;
	cin >> lnN;
	cin >> lnM;

	char nMatrixN[50][50];
	memset(nMatrixN, NULL, sizeof(nMatrixN));
	for (int i = 0; i < lnN; i++)
	{
		cin >> nMatrixN[i];
	}

	char nMatrixM[50][50];
	memset(nMatrixM, NULL, sizeof(nMatrixM));
	for (int i = 0; i < lnM; i++)
	{
		cin >> nMatrixM[i];
	}

	bool bJubge = false;
	for (int i = 0; i <= (lnN-lnM); i++)
	{
		for (int j = 0; j <= (lnN-lnM); j++)
		{
			// MatrixMのループ用
			bool bMatch = true;
			for (int k = 0; k < lnM; k++)
			{
				if (0 != strncmp(&nMatrixN[i + k][j], nMatrixM[k], lnM))
				{
					bMatch = false;
					break;
				}
			}

			if (true == bMatch)
			{
				bJubge = true;
				goto JUDGE;
			}
		}
	}

JUDGE:
	if (true == bJubge)
		cout << "Yes";
	else
		cout << "No";
	return 0;
}
