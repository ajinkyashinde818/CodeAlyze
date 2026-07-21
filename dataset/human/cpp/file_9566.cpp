#include <iostream>
#include <cmath>
#include <complex>
#include <string>
#include <sstream>
#include <limits>
#include <numeric>
#include <algorithm>
#include <functional>

#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N, M;
	cin >> N >> M;

	vector<string> vA;
	for (int i = 0; i < N; i++)
	{
		string a;
		cin >> a;

		vA.push_back(a);
	}

	vector<string> vB;
	for (int i = 0; i < M; i++)
	{
		string b;
		cin >> b;

		vB.push_back(b);
	}

	for (int i = 0; i <= N - M; i++)
	{
		for (int j = 0; j <= N - M; j++)
		{
			bool check = true;
			for (int k = 0; k < M; k++)
			{
				for (int q = 0; q < M; q++)
				{
					if (vA[i + k][j + q] != vB[k][q])
					{
						check = false;
						break;
					}
				}

				if (!check) break;
			}

			if (check)
			{
				cout << "Yes";
				return 0;
			}
		}
	}

	cout << "No";

	return 0;
}
